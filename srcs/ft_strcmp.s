.intel_syntax:

global _ft_strcmp

_ft_strcmp:
	cmp [rdi], byte 0	; if the first string is done
	je ft_strcmp_stop
	cmp [rsi], byte 0	; if the second string is done
	je ft_strcmp_stop
	
	cmp rdi, rsi		; compare string 1 byte to string 2 byte
	jne ft_strcmp_stop
	
	inc rdi				; next rdi byte
	inc rsi				; next rsi byte
	jmp _ft_strcmp		; call next iteration on new byte


ft_strcmp_stop:
	mov rax, [rdi]		; storing first string
	mov rbx, [rsi]		; storing second string
	sub rax, rbx		; get difference

	cmp rax, 0			; if diff < 0
	jl ft_strcmp_less
	cmp rax, 0			; if diff > 0
	jg ft_strcmp_more
	
	ret					; rax == 0

ft_strcmp_less:
	mov rax, -1	; put -1 in return register
	ret

ft_strcmp_more:
	mov rax, 1	; put 1 in return register
	ret
