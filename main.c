/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calle <calle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:20:34 by calle             #+#    #+#             */
/*   Updated: 2021/05/04 18:54:52 by calle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"


//void	ft_strlen_test()
//{
//	char	*s1;
//	char	*s2;
//	char	*s3;
//	char	*s4;
//
//	s1 = "Hello";
//	s2 = "Hello World";
//	s3 = "Hello World, How are you doing ? I am very fine myself!";
//	s4 = "";
//	/* Testing ft_strlen */
	//printf("-------TEST FT_STRLEN--------");
//	printf("len of 'Hello' is %ld\n", ft_strlen(s1));
//	printf("len of 'Hello World' is %ld\n", ft_strlen(s2));
//	printf("len of a long sentence is %ld\n", ft_strlen(s3));
//	printf("len of '' is %ld\n", ft_strlen(s4));
//}

//void	ft_read_test()
//{
//
//	int		fd;
//	char	buf_32[32];
//	char	buf_128[128];
//	int		ret;
//	char	*file;
//
//	file = "file_to_read.txt";
//	fd = open(file, O_RDWR);
//	printf(">>-------TEST FT_READ--------<<\n");
//	printf(">> Reading 32 chars from valid fd '%s'\n", file);
//	ret = ft_read(fd, buf_32, 32);
//	buf_32[31] = 0;
//	printf("RETURNS -- ft_read ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
//	printf("Buffer content - '%s'\n", buf_32);
//	close(fd);
//	fd = open(file, O_RDWR);
//	printf(">> Reading 128 char from valid fd '%s'\n", file);
//	ret = ft_read(fd, buf_128, 128);
//	buf_128[127] = 0;
//	printf("RETURNS -- ft_read ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
//	printf("Buffer content - '%s'\n", buf_128);
//	close(fd);
//	printf(">> Reading 128 char from not opened fd\n");
//	fd = 42;
//	ret = ft_read(fd, buf_128, 128);
//	buf_128[127] = 0;
//	printf("RETURNS -- ft_read ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
//	printf(">> Reading 128 char from negative fd\n");
//	fd = -42;
//	ret = ft_read(fd, buf_128, 128);
//	buf_128[127] = 0;
//	printf("RETURNS -- ft_read ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
//	printf(">> Reading 128 char from stdin\n");
//	fd = 0;
//	ret = ft_read(fd, buf_128, 128);
//	buf_128[127] = 0;
//	printf("RETURNS -- ft_read ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
//}

//void	ft_write_test()
//{
//	int		fd;
//	char	*buf;
//	size_t	count;
//	int		ret;
//	char	*file;
//
//	buf = "Hello World\n";
//	count = 12;
//	file = "file_to_write.txt";
//	printf("-------TEST FT_WRITE--------\n");
//	fd = open(file, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
//	printf(">> Writting %s to %s\n", buf, file);
//	ret = ft_write(fd, buf, count);
//	printf("RETURNS -- ft_write ret = %d -- errno = %d\n", ret, errno);
//	printf(">> Writting %s to %s with count set to zero\n", buf, file);
//	ret = ft_write(fd, buf, 0);
//	printf("RETURNS -- ft_write ret = %d -- errno = %d\n", ret, errno);
//	close(fd);
//	fd = 0;
//	printf(">> Writting %s to stdout\n", buf);
//	ret = ft_write(fd, buf, count);
//	printf("RETURNS -- ft_write ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
//	fd = 40;
//	printf(">> Writting %s to unknown fd\n", buf);
//	ret = ft_write(fd, buf, count);
//	printf("RETURNS -- ft_write ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
//	fd = -1;
//	printf(">> Writting %s to negative fd\n", buf);
//	ret = ft_write(fd, buf, count);
//	printf("RETURNS -- ft_write ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
//}

//void	ft_strcpy_test()
//{
//	const char	*src_1;
//	char		dest_1[12];
//	const char	*src_2;
//	char		dest_2[12];
//	char		dest_3[1];
//
//	src_1 = "Hello World";
//	src_2 = "";
//	printf("-------TEST FT_STRCPY--------\n");
//	printf(">> Copying '%s' to dest of size 12\n", src_1);
//	ft_strcpy(dest_1, src_1);
//	printf("dest = '%s' -- src = '%s'\n", dest_1, src_1);
//	printf(">> Copying '%s' to dest of size 1\n", src_1);
//	ft_strcpy(dest_3, src_1);
//	printf("dest = '%s' -- src = '%s'\n", dest_3, src_1);
//	printf(">> Copying '%s' to dest of size 12\n", src_2);
//	ft_strcpy(dest_2, src_2);
//	printf("dest = '%s' -- src = '%s'\n", dest_2, src_2);
//}

void	ft_strdup_test()
{
	const char	*src_1;
	const char	*src_2;
	char		*dup_1;
	char		*dup_2;

	src_1 = "Hello World";
	src_2 = "";
	printf("-------TEST FT_STRDUP--------\n");
	printf(">> Duplicating '%s'\n", src_1);
	dup_1 = ft_strdup(src_1);
	printf("dup = '%s' -- src = '%s'\n", dup_1, src_1);
	printf("RETURNS -- errno = %d -- strerror = %s\n", errno, strerror(errno));
	printf(">> Duplicating '%s'\n", src_1);
	dup_2 = ft_strdup(src_2);
	printf("dup = '%s' -- src = '%s'\n", dup_2, src_2);
	printf("RETURNS -- errno = %d -- strerror = %s\n", errno, strerror(errno));
	free(dup_1);
	free(dup_2);
}
int		main()
{
//	ft_strlen_test();
//	ft_read_test();
//	ft_write_test();
//	ft_strcpy_test();
	ft_strdup_test();
	return(0);
}
