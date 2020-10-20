section .intel_syntax

global ft_write

section .text

ft_write:

	mov rax, 0x2000004	; mac write syscall code
	syscall				; rdi = fd, rsi = string, rdx = nbytes

	jc error			; if the write return have Carry Flag / is negative
	ret

error:
	mov rax, -1			; set error code
	ret

