#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	    *get_next_line(int fd);
size_t		ft_len(char *str);
char	    *ft_join(char *s1, char *s2);
char		ft_cleaner(char *str);

#endif
