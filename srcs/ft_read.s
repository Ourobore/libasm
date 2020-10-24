section .intel_syntax

global ft_read
extern __errno_location

section .text

ft_read:
	mov rax, 0				; linux syscall code for read
	syscall					; rdi = fd, rsi = buffer, rdx = nbytes

	cmp rax, 0				; if read syscall return is negative
	jl error				; jump to error segment
	ret

error:
	neg rax					; positive value of errno
	mov rdx, rax			; move syscall return (eerno value) into rdx
	call __errno_location	; get errno adress
	mov [rax], rdx			; put errno value into errno location
	mov rax, -1				; set error code
	ret
