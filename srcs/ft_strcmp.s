section .intel_syntax

global ft_strcmp

ft_strcmp:
	mov al, [rdi]
	sub al, [rsi]		; diff stored in 1 byte reg

	cmp [rdi], byte 0	; if the first string is done
	je stop
	cmp [rsi], byte 0	; if the second string is done
	je stop
	
	cmp al, 0			; if there is a diff
	jne stop
	
	inc rdi				; next rdi byte
	inc rsi				; next rsi byte
	jmp ft_strcmp		; call next iteration with new bytes


stop:
	movsx rax, al		; putting back the signed diff in rax
	ret
