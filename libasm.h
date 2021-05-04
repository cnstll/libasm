/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calle <calle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:16:14 by calle             #+#    #+#             */
/*   Updated: 2021/05/04 18:38:29 by calle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
#define LIBASM_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t		ft_strlen(char *str);
ssize_t		ft_read(int fd, void *buf, size_t count);
ssize_t		ft_write(int fd, const void *buf, size_t count);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *s);
#endif
