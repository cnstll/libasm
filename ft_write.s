;ssize_t write(int fd, const void *buf, size_t count)

global ft_write
ft_write:
	;mov	edx, count
	;mov	ecx, buf
	;mov	ebx, fd
	mov		eax, 4
	int		0x80
	ret
