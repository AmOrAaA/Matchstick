/*
** get_next_line.h for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Mon Feb 20 21:22:42 2017 Florian Testu
** Last update Sun Feb 26 18:25:01 2017 Florian Testu
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define READ_SIZE (4)

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int             my_strlen (char *a);
char            *my_strcat(char *dest, char *src);
char            *my_strdup(char *str);
char            *my_save(char *str, int i, int j);
char            *get_next_line(const int fd);

#endif
