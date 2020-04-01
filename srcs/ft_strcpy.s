.intel_syntax:

global _ft_strcpy

_ft_strcpy:
	push rcx
	xor rcx, rcx

loop:
	mov rdi, rsi

	cmp [rsi], byte 0
	je back_loop

	inc rdi
	inc rsi
	inc rcx
	
	jmp loop

ft_strcpy_stop:
	mov rax, rdi
	pop rcx
	ret

back_loop:
	cmp rcx, 0
	je ft_strcpy_stop
	dec rcx
	dec rdi
	jmp back_loop
