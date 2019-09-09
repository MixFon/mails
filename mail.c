
#include "mail.h"

void	*ft_memset(void *b, int c, size_t len);

void print_massage(char *str, char *tail, t_mail *mail)
{
	int i;

	i = 0;
	printf("%s\nУНПК МФТИ\n\n", mail->email);
	while (str[i] != '\0')
	{
		if (strncmp(&str[i], "[1]", 3) == 0)
		{
			printf("%s", mail->name_par);
			i += 3;
		}
		if (strncmp(&str[i], "[2]", 3) == 0)
		{
			printf("%s", mail->name);
			i += 3;
		}
		if (strncmp(&str[i], "[3]", 3) == 0)
		{
			printf("%s", mail->kem);
			i += 3;
		}
		if (strncmp(&str[i], "[4]", 3) == 0)
		{
			printf("%s", mail->kogo);
			i += 3;
		}
		if (strncmp(&str[i], "[5]", 3) == 0)
		{
			printf("%s", mail->komu);
			i += 3;
		}
		if (strncmp(&str[i], "[m]", 3) == 0)
		{
			if (strncmp(mail->sex,"M", 1) == 0)
				printf("%s", "он");
			else
				printf("%s", "она");
			i += 3;
		}
		if (strncmp(&str[i], "[l]", 3) == 0)
		{
			
			printf("%s", mail->link);
			i += 3;
		}
		if (strncmp(&str[i], "[v]", 3) == 0)
		{
			if (strncmp(mail->sex,"M", 1) == 0)
				printf("%s %s %s", "Ваш сын", mail->name, "учился");
			else
				printf("%s %s %s", "Ваша дочь", mail->name, "училась");
			i += 3;
		}
		if (strncmp(&str[i], "[p]", 3) == 0)
		{
			if (strncmp(mail->sex,"M", 1) == 0)
				printf("%s %s %s","показал себя способным и ответственным учеником. Во время учебной смены", mail->name, "активно участвовал в занятиях, выходил к доске и, в целом, проявлял большую заинтересованность в предмете.");
			else
				printf("%s %s %s","показала себя способным и ответственным учеником. Во время учебной смены", mail->name, "активно участвовала в занятиях, выходила к доске и, в целом, проявляла большую заинтересованность в предмете.");
			i += 3;
		}
		if (strncmp(&str[i], "[x]", 3) == 0)
		{
			if (strncmp(mail->sex,"W", 1) == 0)
				printf("%s","а");
			i += 3;
		}
		printf("%c", str[i]);
		i++;
	}
	printf("%s\n", tail);
}

void	read_data(t_mail *mail)
{
	char *line;
	
	line = NULL;
	get_next_line(mail->fd_name, &line);
	strncpy(mail->name, line, strlen(line));
	free(line);
	get_next_line(mail->fd_name, &line);
	strncpy(mail->kem, line, strlen(line));
	free(line);
	get_next_line(mail->fd_name, &line);
	strncpy(mail->kogo, line, strlen(line));
	free(line);
	get_next_line(mail->fd_name, &line);
	strncpy(mail->komu, line, strlen(line));
	free(line);
	get_next_line(mail->fd_name, &line);
	strncpy(mail->sex, line, strlen(line));
	free(line);

	get_next_line(mail->fd_par, &line);
	strncpy(mail->name_par, line, strlen(line));
	free(line);
	
	get_next_line(mail->fd_email, &line);
	strncpy(mail->email, line, strlen(line));
	free(line);
	printf("\n-------------------------------------------- || -------------------------------------------- \n\n");
}

void	open_data(t_mail *mail)
{
	char *line;

	if ((mail->fd_name = open("lsh_msk_fm9-10/nameC", O_RDONLY)) == -1)
	{
		write(2, "File name missing.\n", 19);
		exit(0);
	}
	if ((mail->fd_par = open("lsh_msk_fm9-10/nameP", O_RDONLY)) == -1)
	{
		write(2, "File name missing.\n", 19);
		exit(0);
	}
	if ((mail->fd_email = open("lsh_msk_fm9-10/email", O_RDONLY)) == -1)
	{
		write(2, "File name missing.\n", 19);
		exit(0);
	}
	if ((mail->fd_link = open("lsh_msk_fm9-10/link", O_RDONLY)) == -1)
	{
		write(2, "File name missing.\n", 19);
		exit(0);
	}
	get_next_line(mail->fd_link, &line);
	strncpy(mail->link, line, strlen(line));
	free(line);
}

void	close_file(t_mail *mail)
{
	close(mail->fd_name);
	close(mail->fd_par);
	close(mail->fd_email);
	close(mail->fd_link);
}

void	delete_string(t_mail *mail)
{
	ft_memset(mail->name, '\0', 400);	
	ft_memset(mail->name_par, '\0', 400);	
	ft_memset(mail->email, '\0', 400);	
	ft_memset(mail->kem, '\0', 400);	
	ft_memset(mail->kogo, '\0', 400);	
	ft_memset(mail->komu, '\0', 400);	
	ft_memset(mail->sex, '\0', 400);	
}

int main(void)
{
	t_mail	mail;
	int		i;
	int		count;
	
	i = -1;
	count = 10;
	setlocale(LC_ALL, "Rus");
	char str[] = STR;
	char str2[] = STR2;
	char str3[] = STR3;
	char tail[] = TAIL;
	open_data(&mail);
	while(++i < count)
	{
		delete_string(&mail);
		read_data(&mail);
		if (i % 3 == 0)
			print_massage(str, tail, &mail); 
		else if (i % 3 == 1)
			print_massage(str2, tail, &mail); 
		else
			print_massage(str3, tail, &mail); 
		delete_string(&mail);
	}
	close_file(&mail);

return (0);
}
