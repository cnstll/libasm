;ssize_t read(int fd, void *buf, size_t count)
global ft_read

ft_read:
	;mov	rdx, count
	;mov	rcx, buf
	;mov	rbx, fd
	mov		rax, 3
	int		0x80
	ret
