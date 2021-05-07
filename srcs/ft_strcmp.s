;int ft_strcmp(const char *s1, const char *s2)

global ft_strcmp

SECTION .text
ft_strcmp:
									;prologue, building stack frame for our fonction
	push	rbp						;saving address of stack base
	mov		rbp, rsp				;top of the stack becomes bottom of the stack
	push	rbx
									;function call parameters are saved in these registers
									;rdi < s1
									;rsi < s2
	mov		rcx, 0
	xor		rax, rax				;clean rax, if the bits from the operands are the same the results of the xoring is 0
	loop:
		;using movzx to sign-extended the byte into a 32bits register
		movzx	eax, BYTE [rdi + rcx]	;move s1 in eax
		movzx	ebx, BYTE [rsi + rcx]	;move s2 in ebx
		cmp		eax, 0					;check if *s1 is == 0
		jz		done
		cmp		ebx, eax				;cmp *s1,*s2
		jne		done					;if *s1 and *s2 are not equal jmp
		inc		rcx						;else increment index
		jmp		loop
	done:
		sub		eax, ebx					;compare the chars
		;epilogue
		pop		rbx
		mov		rsp, rbp
		pop		rbp
		ret
