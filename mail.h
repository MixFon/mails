#ifndef LIBFT_H
# define LIBFT_H

//#include "libft/ft_printf.h"
#include "libft/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define	STR "Добрый день, [1]!\n\n\nЯ, Ярослав Дмитриевич, куратор Летней школы в Долгопрудном, хочу сказать Вам Спасибо за то, что выбрали УНПК МФТИ!\n\n[v] у нас на летней школе на физико-математическом направлении. За время летней школы [2] [p] По результатам летней школы, все преподаватели, работавшие с [3], отметили значительное повышение уровня знаний.\n\nМы очень хотим, чтобы [2] успешно продолжал[x] изучение физики и математики, поэтому просим Вас обратить внимание [4] на решение всех четных задач.\n\nhttps://drive.google.com/open?id=1tEHFYTG7zIMERoLPkjYdpDCY1yB3aZsg\n\nНачало учебного года - очень ответственное время. Будет крайне полезно, если [2] дополнительно самостоятельно проработает эти темы и задачи.\n\nТакже вы можете продолжить обучение с нашими преподавателями в одном из учебных центров в Москве или Долгопрудном. Групповые занятия помогут [5] качественно повысить уровень своих знаний, и достичь отличного результата в изучении физики и математики. Но стоит поспешить: занятия в наших учебных центрах начнутся уже 14-го сентября, и мест в группах осталось совсем мало.\n\n[2] является перспективным учеником, и мы очень надеемся, что [m] покажет высокий результат на экзаменах. Мы готовы сделать все возможное, чтобы помочь с этим. \n\nИ у нас к вам небольшая просьба - ответьте, пожалуйста, на несколько вопросов в Google-форме, чтобы сделать УНПК МФТИ еще лучше. Это займёт от 1 до 3 минуты.\n"

#define TAIL "Если вас заинтересовало обучение на курсах в течение учебного года отметьте соответствующий пункт в анкете.\n\nhttps://docs.google.com/forms/d/1tPKmvYwEvblpANPSYmvJkUzv_senRiSNrXPgddiIm3A/viewform?edit_requested=true \n\nЗаранее спасибо за ваш отзыв!\n\nС уважением, \nЯрослав Дмитриевич." 

typedef struct	s_mail
{
	int		fd_name;
	int		fd_par;
	int		fd_email;
	char	name[500];
	char	name_par[500];
	char	email[500];
	char	kem[500];
	char	kogo[500];
	char	komu[500];
	char	sex[500];
			
}				t_mail;

#endif