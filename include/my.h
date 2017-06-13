/*
** my.h for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick/include
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Mon Feb 20 12:23:00 2017 Florian Testu
** Last update Fri Feb 24 22:23:04 2017 Florian Testu
*/

#ifndef MY_H_
# define MY_H_

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "struct.h"
# include "cond.h"
# include "my_tr.h"

void		my_putchar(char z);
void		my_putstr(char *str);
int		my_getnbr(char *str);
void		print_map(char **tab);
void		my_putnbr(int nb);

int		check_error_line(t_tr my_tr, int stick, char **tab);
int		check_error_str(char *str);
int		check_error_ptr(char *ptr);

int		check_lose_ia(char **tab);
int		check_lose_player(char **tab);

int	        my_game(char **tab, t_match *compt);
char	        **player(char **tab, t_tr my_tr, t_match *compt);

char	        **check_str_ptr(char **tab, t_match *compt);
int		check_er_ptr2(char **tab, int the_line, int stick, int x);
int	        check_er_ptr(char *ptr, char *str, int x, t_match *compt, int stick);
void	        check_theline(char *str);
int		verif_stick(char *str, char *ptr, t_match *compt, int x);
char		**print_player(char **tab, t_tr my_tr, t_match *compt);

int		compt_stick(char **tab, int result);
int	        cond_1_4(t_tr my_tr,  t_match *compt, int x);
void	        cond_0(t_tr my_tr);
int	        cond_5(char **tab, t_tr my_tr,  t_match *compt);
int		cond_1_5(char ***tab, int result, t_match *compt, t_cond cond);
char		**cond_1_2(char **tab, t_match *compt);
int             cond_1_0(char ****tab, t_match *compt);
int	        cond_1_1(char ****tab, int result, t_cond cond, t_match *compt);
char		**cond_1(char **tab, t_match *compt, int result);
char		**cond_2(char **tab, int col, t_match *compt);
char		**cond_2_1(char **tab, int i, t_match *compt);
char		**cond_3(char **tab, int col, t_match *compt);
char		**cond_4(char **tab);

int		my_strlen_at_the_line(char *str);
int		my_len_space(char *str);
char		**my_str_to_wordtab(char *str);
char            *get_next_line(const int fd);

char		**my_turn_map(int lin, int col);
int		my_map(int argc, char **argv);
int		gest_error(int argc, char **argv);
char		**my_put_stick(char **tab, t_match *compt);

#endif
