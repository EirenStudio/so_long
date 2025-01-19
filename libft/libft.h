/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenbeita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:15:23 by jenbeita          #+#    #+#             */
/*   Updated: 2024/09/18 12:15:25 by jenbeita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *s);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *inp, const void *valor, size_t bytes);
void				*ft_memmove(void *inp, const void *valor, size_t bytes);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *src);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstelm(void *content);
void				ft_lstadd_front(t_list **alst, t_list *elm);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *elm);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*ft_lstmap(t_list *lst,
						void *(*f)(void *), void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
//PRINTF
int					ft_printf(const char *str, ...);
int					ft_print_ptr(void *ptr);
int					ft_print_uint(unsigned int n);
int					ft_print_str(char *str);
int					ft_print_int(int num);
int					ft_print_char(char c);
int					ft_print_hex(unsigned int n, int minus);
//GNL
char				*get_next_line(int fd);

#endif
