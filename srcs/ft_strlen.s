.intel_syntax

ft_strlen:
	push rcx			; save counter / put the value on top of the stack
	xor rcx, rcx		; erase counter / set to 0
	jmp ft_strlen_loop	; start the counting loop

ft_strlen_loop:
	cmp [rdi], byte 0	; check if the byte is null
	jz ft_strlen_null	; then end the loop

	inc rcx				; else increment counter
	inc rdi				; go to next byte
	jmp ft_strlen_loop	; next iteration of the loop

ft_strlen_end:
	mov rax, rcx		; move counter in rax / return value
	pop rcx				; put back the original back into rax

	ret					; return rax / stop function
