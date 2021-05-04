;ssize_t read(int fd, void *buf, size_t count)
;PLT stands for Procedure Linkage table, it is used for calling outside procedures.

extern __errno_location
global ft_read

SECTION .TEXT
ft_read:
	;prologue
	push	rbp ; saving address of stack bottom
	mov		rbp, rsp ; top of the stack becomes bottom of the stack
	;function call parameters are saved in these registers
	;rdi < fd
	;rsi < buf
	;rdx < count
	mov		rax, 0
	syscall ; calling read with opcode 0
	cmp		rax, 0 ; cmp return value of sys_call
	jl		error ; error in case rax is between -1 & -4095, else success
	mov		rsp, rbp
	pop		rbp
	ret
error:
	neg		rax
	mov		rdi, rax ; loading error value for errno call
	call	__errno_location wrt ..plt
	mov		[rax], rdi ;
	mov		rax, -1
	;epilogue
	mov		rsp, rbp
	pop		rbp
	ret
