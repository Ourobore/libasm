.intel_syntax:

global _ft_write

section .text

_ft_write:

	mov rax, 0x2000004	; mac write syscall code
	syscall

	;mov rax, rdx
	ret

