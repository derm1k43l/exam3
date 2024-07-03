/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnll.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:48:34 by mrusu             #+#    #+#             */
/*   Updated: 2024/07/03 17:49:41 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNLL_H
# define GNLL_H

# include <unistd.h> // for read
# include <stdlib.h> // for malloc
# include <stdio.h> // for printf and End Of File
# include <fcntl.h> // for open txt file
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

#endif