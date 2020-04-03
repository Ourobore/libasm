.intel_syntax

global _ft_read

section .text

_ft_read:
	mov rax, 0x2000003	; mac syscall code for read
	syscall				; rdi = fd, rsi = buffer, rdx = nbytes

	jc error			; if return value is negative / Carry Flag
	ret

error:
	mov rax, -1			; set error code
	ret
