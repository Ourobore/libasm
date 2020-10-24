section .intel_syntax

global ft_write
extern __errno_location

section .text

ft_write:
	mov rax, 1				; linux write syscall code
	syscall					; rdi = fd, rsi = string, rdx = nbytes

	cmp rax, 0				; if write syscall return  is negative
	jl error				; jump to error segment
	ret

error:
	neg rax					; positive value of errno
	mov rdx, rax			; errno value from syscall return moved into rdx
	call __errno_location	; get adress of errno
	mov [rax], rdx			; put errno value into errno location
	mov rax, -1				; set error code
	ret

