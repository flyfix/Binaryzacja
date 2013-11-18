

.data
	red real8 0.299
	green real8 0.587						 ; color rates
	blue real8 0.1140000000000001
.code
	
	;void asmBinaryzation(unsigned char * img ,int size, int intensy)
	;RCX - img
	;RDX - size(how many pixel consist of)
	;R8 - intensy

	asmBinaryzation proc
		
		mov r9, 0  ; set   image offset pointer to 0

		MainLoop:
	
			mov eax, 0
			mov al, byte ptr [rcx + r9 + 0];
			xorps xmm0, xmm2
			mulsd xmm0, blue                  ; Multiply blue with rate

			mov eax, 0
			mov al, byte ptr [rcx + r9 + 1];
			xorps xmm1, xmm1
			mulsd xmm1, green				  ; Multiply green with rate

			mov eax, 0
			mov al, byte ptr [rcx + r9 + 2];
			xorps xmm2, xmm2
			mulsd xmm2, red                   ; Multiply red with rate

			addsd xmm0, xmm1
			addsd xmm0,xmm2					  ; add results of multiples
			
			mov ax,0
			cvtsi2sd xmm3, r8
			comisd  xmm0, xmm3                ; compare added result of multiples with intensy rate
			ja NotAbove
			mov ax,255
			NotAbove:
			mov byte ptr [rcx + r9 + 0], al
			mov byte ptr [rcx + r9 + 1], al
			mov byte ptr [rcx + r9 + 2], al

			add r9, 4						  ; jump to next pixel
			dec rdx
			jnz MainLoop                      ; jump to loop if image not ends

		ret
	asmBinaryzation endp

end
