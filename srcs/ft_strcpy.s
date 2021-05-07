;char *ft_strcpy(char *dest, const char *src)

global ft_strcpy

SECTION .text
ft_strcpy:
	;prologue
	push	rbp ; saving address of stack bottom
	mov		rbp, rsp ; top of the stack becomes bottom of the stack
	push	rbx
	;function call parameters are saved in these registers
	;rdi < dest
	;rsi < src
	mov		rcx, 0
	loop:
		mov		bl, BYTE [rsi + rcx]
		cmp		bl, 0
		jz		done
		mov		BYTE [rdi + rcx], bl
		inc		rcx
		jmp		loop
	done:
		mov		BYTE [rdi + rcx], bl
		mov		rax, rdi
		;epilogue
		pop		rbx
		mov		rsp, rbp
		pop		rbp
		ret
