.intel_syntax:

global _ft_strdup

extern _ft_strlen
extern _ft_strcpy
extern _malloc

_ft_strdup:
	push rdi		; saving the source
	call _ft_strlen	; getting string length
	;pop rdi			; getting back source

	add rax, 1		; adding 1 to string length for \0
	;push rdi		
	mov rdi, rax	; moving length to rdi / first argument for malloc

	call _malloc	; allocating memory to rax
	pop rsi			; putting back source in rsi / second argument
	
	cmp rax, 0		; if rax <= 0 then error
	jle error

	mov rdi, rax	; putting dest in rdi / first argument
	call _ft_strcpy	; copying src to dest

	ret

error:
	xor rax, rax	; set rax at NULL
	ret
	
