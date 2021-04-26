;size_t ft_strlen(const char *)
global ft_strlen

SECTION .text
ft_strlen:
	push	rbp
	mov		rbp, rsp
	push	rbx
	mov		rax, rbx
	loop:
		cmp		byte [rax], 0
		jz		done
		inc		rax
		jmp		loop
	done:
		sub		rax, rbx
		pop		rbx
		mov		rsp, rbp
		pop		rbp
		ret
