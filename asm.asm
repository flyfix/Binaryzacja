

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
		
		xor r9, r9  ; set   image offset pointer to 0

		MainLoop:
	
			xor eax, eax
			mov al, byte ptr [rcx + r9 + 0];
			cvtsi2sd xmm0, eax
			mulsd xmm0, blue                  ; Multiply blue with rate

			xor eax, eax
			mov al, byte ptr [rcx + r9 + 1];
			cvtsi2sd xmm1, eax
			mulsd xmm1, green				  ; Multiply green with rate

			xor eax, eax
			mov al, byte ptr [rcx + r9 + 2];
			cvtsi2sd xmm2, eax
			mulsd xmm2, red                   ; Multiply red with rate

			addsd xmm0, xmm1
			addsd xmm0,xmm2					  ; add results of multiples
			
			xor ax, ax
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

	;double asmAvgLum(unsigned char * img ,int size);
	;RCX - img
	;RDX - size(how many pixel consist of)

	asmAvgLum proc

		xor r8, r8  ; set   image offset pointer to 0
		xorpd xmm3, xmm3 ; set avg lum to 0

		MainLoop:
	
			xor eax, eax
			mov al, byte ptr [rcx + r8 + 0];
			cvtsi2sd xmm0, eax
			mulsd xmm0, blue                  ; Multiply blue with rate

			xor eax, eax
			mov al, byte ptr [rcx + r8 + 1];
			cvtsi2sd xmm1, eax
			mulsd xmm1, green				  ; Multiply green with rate

			xor eax, eax
			mov al, byte ptr [rcx + r8 + 2];
			cvtsi2sd xmm2, eax
			mulsd xmm2, red                   ; Multiply red with rate

			addsd xmm0, xmm1
			addsd xmm0,xmm2					  ;compute luminance of pixel
			
			addsd xmm3, xmm0                  ;sum luminance of picture

			add r9, 4						  ; jump to next pixel
			dec rdx
			jnz MainLoop                      ; jump to loop if image not ends

			cvtsi2sd xmm4, rdx
			divsd xmm3,xmm4
			cvtsd2si rax,xmm3
		
		ret
	asmAvgLum endp

end
