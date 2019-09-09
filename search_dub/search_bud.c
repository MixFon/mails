
#include "search_dub.h"

void	ft_strdel(char **line);

int		search_dub(char *line)
{
	int		fd_base;
	char	*line_base;

	if ((fd_base = open("data_base", O_RDONLY)) == -1)
	{
		write(2, "File name missing.\n", 19);
		exit(0);
	}
	while (get_next_line(fd_base, &line_base) > 0)
	{
		if (strncmp(line, line_base, strlen(line_base)) == 0)
		{
			printf(" ------------- dub {%s}\n", line);
			close(fd_base);
			free(line_base);
			return (1);
		}
		free(line_base);
	}
	close(fd_base);
	return (0);
}

int main(void)
{
	int		fd_mail;
	char	*line;
	
	if ((fd_mail = open("email", O_RDONLY)) == -1)
	{
		write(2, "File name missing.\n", 19);
		exit(0);
	}
	while (get_next_line(fd_mail, &line) > 0)
	{
		if(!(search_dub(line)))
			printf("%s\n", line);
		free(line);
	}
	close(fd_mail);
	return (0);
}
