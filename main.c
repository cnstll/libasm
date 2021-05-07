/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calle <calle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:20:34 by calle             #+#    #+#             */
/*   Updated: 2021/05/07 15:09:29 by calle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/libasm.h"


void	ft_strlen_test()
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;

	s1 = "Hello";
	s2 = "Hello World";
	s3 = "Hello World, How are you doing ? I am very fine myself!";
	s4 = "";
	/* Testing ft_strlen */
	printf("\n\n-------TEST FT_STRLEN--------\n\n");
	printf("RETURN -- len of '%s' is %ld <> EXPECTED RETURN -- %ld\n", s1, ft_strlen(s1), strlen(s1));
	printf("RETURN -- len of '%s' is %ld <> EXPECTED RETURN -- %ld\n", s2, ft_strlen(s2), strlen(s2));
	printf("RETURN -- len of '%s' is %ld <> EXPECTED RETURN -- %ld\n", s3, ft_strlen(s3), strlen(s3));
	printf("RETURN -- len of '%s' is %ld <> EXPECTED RETURN -- %ld\n", s4, ft_strlen(s4), strlen(s4));
}

void	ft_strcmp_test()
{
	const char	*s1;
	const char	*s2;
	const char	*d1;
	const char	*d2;
	const char	*e1;
	const char	*e2;
	const char	*f1;
	const char	*f2;
	const char	*g1;
	const char	*g2;
	int			ret;

	s1 = "Hello World";
	s2 = "Hello World";
	d1 = "Hello Wor";
	d2 = "Hello World";
	e1 = "Hello World";
	e2 = "Hello Wor";
	f1 = "";
	f2 = "Hello World";
	g1 = "Hella World";
	g2 = "Hello World";
	printf("\n\n-------TEST FT_STRCMP--------\n\n");
	printf(">> Comparing '%s' and '%s'\n", s1, s2);
	ret = ft_strcmp(s1, s2);
	printf("RETURN -- %d <> EXPECTED RETURN -- %d\n", ret, strcmp(s1,s2));
	printf(">> Comparing '%s' and '%s'\n", d1, d2);
	ret = ft_strcmp(d1, d2);
	printf("RETURN -- %d <> EXPECTED RETURN -- %d\n", ret, strcmp(d1,d2));
	printf(">> Comparing '%s' and '%s'\n", e1, e2);
	ret = ft_strcmp(e1, e2);
	printf("RETURN -- %d <> EXPECTED RETURN -- %d\n", ret, strcmp(e1,e2));
	printf(">> Comparing '%s' and '%s'\n", f1, f2);
	ret = ft_strcmp(f1, f2);
	printf("RETURN -- %d <> EXPECTED RETURN -- %d\n", ret, strcmp(f1,f2));
	printf(">> Comparing '%s' and '%s'\n", g1, g2);
	ret = ft_strcmp(g1, g2);
	printf("RETURN -- %d <> EXPECTED RETURN -- %d\n", ret, strcmp(g1,g2));
}

void	ft_strcpy_test()
{
	const char	*src_1;
	char		dest_1[12];
	const char	*src_2;
	char		dest_2[12];
	char		dest_3[1];

	src_1 = "Hello World";
	src_2 = "";
	printf("\n\n-------TEST FT_STRCPY--------\n\n");
	printf(">> Copying '%s' to dest of size 12...\n", src_1);
	ft_strcpy(dest_1, src_1);
	printf("RETURN -- dest = '%s' -- src = '%s'\n", dest_1, src_1);
	printf(">> Copying '%s' to dest of size 1...\n", src_1);
	ft_strcpy(dest_3, src_1);
	printf("RETURN -- dest = '%s' -- src = '%s'\n", dest_3, src_1);
	printf(">> Copying '%s' to dest of size 12...\n", src_2);
	ft_strcpy(dest_2, src_2);
	printf("RETURN -- dest = '%s' -- src = '%s'\n", dest_2, src_2);
}

void	ft_read_test()
{

	int		fd;
	char	buf1[128];
	char	buf2[128];
	int		ret;
	char	*file1;
	char	*file2;

	file1 = "file_to_read1.txt";
	file2 = "file_to_read2.txt";
	fd = open(file1, O_RDWR);
	printf("\n\n-------TEST FT_READ--------\n\n");
	printf(">> Reading 32 chars from valid fd '%s'...\n", file1);
	ret = ft_read(fd, buf1, 128);
	buf1[127] = 0;
	printf("RETURNS -- ft_read ret = %d\n", ret);
	printf("BUFFER CONTENT -- '%s'\n", buf1);
	close(fd);
	fd = open(file2, O_RDWR);
	printf(">> Reading 128 char from valid fd '%s'...\n", file2);
	ret = ft_read(fd, buf2, 128);
	buf2[127] = 0;
	printf("RETURNS -- ft_read ret = %d\n", ret);
	printf("BUFFER CONTENT -- '%s'\n", buf2);
	close(fd);
	printf(">> Reading 128 char from not opened fd...\n");
	fd = 42;
	ret = ft_read(fd, buf2, 128);
	buf2[127] = 0;
	printf("RETURNS -- ft_read ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
	printf(">> Reading 128 char from negative fd...\n");
	fd = -42;
	ret = ft_read(fd, buf2, 128);
	buf2[127] = 0;
	printf("RETURNS -- ft_read ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
}

void	ft_write_test()
{
	int		fd;
	char	*buf;
	size_t	count;
	int		ret;
	char	*file;

	buf = "Hello World";
	count = 11;
	file = "file_to_write.txt";
	printf("\n\n-------TEST FT_WRITE--------\n\n");
	fd = open(file, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
	printf(">> Writting %s to %s...\n", buf, file);
	ret = ft_write(fd, buf, count);
	printf("RETURNS -- ft_write ret = %d\n", ret);
	printf(">> Writting %s to %s with count set to 0...\n", buf, file);
	ret = ft_write(fd, buf, 0);
	printf("RETURNS -- ft_write ret = %d\n", ret);
	close(fd);
	fd = 0;
	printf(">> Writting %s to stdout...\n", buf);
	ret = ft_write(fd, buf, count);
	printf("\nRETURNS -- ft_write ret = %d\n", ret);
	fd = 40;
	printf(">> Writting %s to unknown fd...\n", buf);
	ret = ft_write(fd, buf, count);
	printf("RETURNS -- ft_write ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
	fd = -1;
	printf(">> Writting %s to negative fd...\n", buf);
	ret = ft_write(fd, buf, count);
	printf("RETURNS -- ft_write ret = %d -- errno = %d -- strerror = %s\n", ret, errno, strerror(errno));
}

void	ft_strdup_test()
{
	const char	*src_1;
	const char	*src_2;
	const char	*src_3;
	char		*dup_1;
	char		*dup_2;
	char		*dup_3;

	src_1 = "Hello World";
	src_2 = "";
	src_3 = "Hello World, How are you doing ? I am very fine myself!";
	printf("\n\n-------TEST FT_STRDUP--------\n\n");
	printf(">> Duplicating '%s'...\n", src_1);
	dup_1 = ft_strdup(src_1);
	printf("RETURN -- dup = '%s' <> Original  src = '%s'\n", dup_1, src_1);
	printf(">> Duplicating '%s'...\n", src_2);
	dup_2 = ft_strdup(src_2);
	printf("RETURN -- dup = '%s' <> Original src = '%s'\n", dup_2, src_2);
	printf(">> Duplicating '%s'...\n", src_3);
	dup_3 = ft_strdup(src_3);
	printf("RETURN -- dup = '%s' <> Unchanged src = '%s'\n", dup_3, src_3);
	free(dup_1);
	free(dup_2);
	free(dup_3);
}

int		main()
{
	ft_strlen_test();
	ft_strcpy_test();
	ft_strcmp_test();
	ft_read_test();
	ft_write_test();
	ft_strdup_test();
	return(0);
}
