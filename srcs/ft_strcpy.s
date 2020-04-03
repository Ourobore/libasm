.intel_syntax:

global _ft_strcpy

section .text

_ft_strcpy:
	push rcx				; push counter to stack
	xor rcx, rcx			; setting counter at 0
	xor dl, dl				; setting tmp reg at 0

loop:
	mov dl, [rsi + rcx]		; copying rsi to rdi in 2 steps
	mov [rdi + rcx], dl

	cmp [rsi + rcx], byte 0	; if rsi is finished
	je stop

	inc rcx					; incrementing counter
	
	jmp loop				; next loop iteration

stop:
	mov rax, rdi			; putting result in return reg
	pop rcx					; putting back original value in rcx
	ret
