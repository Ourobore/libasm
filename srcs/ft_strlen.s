section .intel_syntax

global ft_strlen

ft_strlen:
	xor rax, rax		; set counter / return value at 0

loop:
	cmp BYTE [rdi], 0	; check if the byte is null
	jz stop				; then stop the loop

	inc rax				; increment counter
	inc rdi				; go to string ext byte
	jmp loop			; next iteration of the loop

stop:
	ret					; return rax / stop function
