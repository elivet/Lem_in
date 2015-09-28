/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:13:46 by elivet            #+#    #+#             */
/*   Updated: 2014/03/22 20:14:25 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define BUFF_SIZE 1

# include <string.h>

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_data
{
	int		nbr;
	int		count;
	char	*found;
	char	*start;
	char	*end;
	char	*line;
	char	**tube;
	int		move;
	char	**link;
	char	**ant;
	char	**way;
	char	**aff;
	int		i;
	int		j;
	int		top;
	int		keep;
	int		what;
	long	stop;
	t_list	*list;
	t_list	*cpy;
}					t_data;

int			get_next_line(int const fd, char **line);
char		*ft_strnew(size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *s1, const char *s2);
char		*join(char *s1, char *s2);
char		*joinch(char *s1, char c);
void		ft_strclr(char *s);
int			ft_atoi(const char *str);
char		ft_nospace(char c);
int			ft_isdigit(int c);
char		**ft_strsplit(char const *s, char c);
int			ft_countwords(char const *s, char c);
int			check_nbr(t_data the);
int			check_tube(char *line);
int			check_room(t_data the);
t_data		information(t_data the);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strdup(char *s1);
char		*take_name(char *line);
int			ft_isdigit_room(char *str);
t_data		ft_link(t_data the);
t_data		save(char *found, t_data the, int top);
t_data		search(t_data the, char *find, int top);
void		ft_putendl(char const *s);
void		ft_putstr(char const *s);
void		ft_putchar(char c);
char		*ft_itoa(int n);
int			ft_sizeofint(int nbr);
char		*add_ant(int i);
t_data		take_ants(t_data the);
t_data		journey(t_data the);
t_data		count_move(t_data the);
void		lets_go(t_data the);
void		check_it(t_data the);
int			check_before(t_data the, char *str, int what);
t_data		ft_delete(t_data the, char *del);
void		error(void);
t_data		first_take(t_data the);
t_data		finish(t_data the, int i, int j);
t_data		take_start(t_data the);
t_data		take_end(t_data the);
t_data		lets_start(t_data the);
t_list		*ft_lstnew(char *data);
void		ft_lstaddtail(t_list **list, char *content, char *start);
t_list		*tab_to_list(t_data the);
int			ft_strequ(char const *s1, char const *s2);
t_data		init_top(t_data the);
t_data		not_found(t_data the, char *tmp);
t_data		first_look(t_data the);
t_data		ft_else(t_data the, char *tmp);
t_data		findandcheck(t_data the, char **tab, char *find);

#endif /* !LEMIN_H */
