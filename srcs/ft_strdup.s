section .intel_syntax

global ft_strdup

extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:			; rdi = 1st param
	push rdi		; saving the source
	call ft_strlen	; getting string length

	add rax, 1		; adding 1 to string length for \0
	mov rdi, rax	; moving length to rdi / first argument for malloc

	call malloc		; allocating memory to rax
	pop rsi			; putting back source in rsi / second argument
	
	cmp rax, 0		; if rax <= 0 then error / malloc error
	jle error

	mov rdi, rax	; putting dest in rdi / first argument
	call ft_strcpy	; copying src to dest

	ret

error:
	xor rax, rax	; set rax at NULL
	ret
	
