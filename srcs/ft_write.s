;ssize_t write(int fd, const void *buf, size_t count)
;PLT stands for Procedure Linkage table, it is used for calling outside procedures.

extern __errno_location
global ft_write

SECTION .TEXT
ft_write:
	;mov	rdi, rdi < fd
	;mov	rsi, rsi < buf
	;mov	rdx, rdx < count
	push	rbp
	mov		rbp, rsp
	mov		rax, 1
	syscall ; calling write with opcode 1
	cmp		rax, 0 ; cmp return value of sys_call
	jl		error ; error in case rax is between -1 & -4095, else success
	mov		rsp, rbp
	pop		rbp
	ret
error:
	neg		rax
	mov		rdi, rax ; sendig error value to errno function
	call	__errno_location wrt ..plt
	mov		[rax], rdi ;
	mov		rax, -1
	mov		rsp, rbp
	pop		rbp
	ret
