.intel_syntax:

global _ft_strcmp

_ft_strcmp:
	mov al, [rdi]
	sub al, [rsi]		; diff stored in 1 byte reg

	cmp [rdi], byte 0	; if the first string is done
	je ft_strcmp_stop
	cmp [rsi], byte 0	; if the second string is done
	je ft_strcmp_stop
	
	cmp al, 0			; if there is a diff
	jne ft_strcmp_stop
	
	inc rdi				; next rdi byte
	inc rsi				; next rsi byte
	jmp _ft_strcmp		; call next iteration with new bytes


ft_strcmp_stop:
	movsx rax, al		; putting back the diff in rax
	ret
