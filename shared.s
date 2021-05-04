;void exit()
;Exiting program

_exit:
	mov		ebx, 0
	mov		eax, 1
	int		0x80
