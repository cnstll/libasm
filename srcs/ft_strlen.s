;size_t ft_strlen(const char *)
global ft_strlen

SECTION .text
ft_strlen:
	push	rbp
	mov		rbp, rsp
	mov		rax, rdi
	loop:
		cmp		byte [rax], 0
		jz		done
		inc		rax
		jmp		loop
	done:
		sub		rax, rdi
		mov		rsp, rbp
		pop		rbp
		ret
