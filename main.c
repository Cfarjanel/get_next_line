#include "get_next_line.h"

int		main(void)
{
	char	*filename;
	char	*line;
	int		fd;
	int		cpt;

	filename = "test.txt";
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strcmp(line, "aaa") == 0)
		{
			cpt++;
			printf("%s\n", line);
		}
		if (ft_strcmp(line, "bbb") == 0)
		{
			cpt++;
			printf("%s\n", line);
		}
		if (ft_strcmp(line, "ccc") == 0)
		{
			cpt++;
			printf("%s\n", line);
		}
		if (ft_strcmp(line, "ddd") == 0)
		{
			cpt++;
			printf("%s\n", line);
		}
		if (cpt >= 10)
			break ;
	}
	close(fd);
	if (cpt == 4)
		printf("Okay");
	return (0);
}
