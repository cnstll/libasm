;char *strdup(const char *s)

extern malloc
extern __errno_location
extern	ft_strlen
extern	ft_strcpy
global ft_strdup

SECTION .text
; rdi < s
ft_strdup:
	;prologue
	push	rbp
	mov		rbp, rsp
	push	rbx
	mov		r8, rdi

	get_len:
		call	ft_strlen
		inc		rax
		mov		rdi, rax
	malloc_mem:
		call	malloc
		cmp		rax, 0			;testing for error
		je		return			;if error return, errno is set by malloc properly
	dup:
		mov		rdi, rax
		mov		rsi, r8
		call	ft_strcpy
	return:
	;epilogue
	pop		rbx
	mov		rsp, rbp
	pop		rbp
	ret
