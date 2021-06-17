# Get_next_line

Ce dépôt contiens ma solution au projet `get_next_line` de 42 (Paris).

This Repositorie contains my solution to the project `get_next_line` of 42 (Paris).

[![jaeskim's 42 stats](https://badge42.herokuapp.com/api/stats/cmaginot?cursus=42cursus&privacyName=true)](https://github.com/JaeSeoKim/badge42)

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/cmaginot/get_next_line)](https://github.com/JaeSeoKim/badge42)

## Using Get_next_line

### Compilation

the value of `BUFFER_SIZE` can be changed
file.c represent other c files

#### For only one file

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c file.c
```

#### For Multiple file

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line_bonus.c get_next_line_utils_bonus.c file.c
```

### Exemple of Uses

```c
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int	fd;
	int	i;
	char	*line = NULL;

		fd = open("test", O_RDONLY);
		if (fd < 0)
			return (-1);
		i = 0;
		while (get_next_line(fd, &line) == 1)
		{
			i++;
			printf("line %i : %s\n", i, line);
		}
		printf("last line : %s", line);
		close(fd);
		printf("%s\n", line);
		free(line);
		return (0);
}
```

## Test

Test effectuer sur un `MacBook Air (M1, 2020)` sous `macOS Big Sur Version 11.2.3` et sur un `iMac (fin 2012)` sous `macOS Mojave Version 10.14.6`

Test done on a `MacBook Air (M1, 2020)` under `macOS Big Sur Version 11.2.3` and on a `iMac (late 2012)` under `macOS Mojave Version 10.14.6`

> [42TESTERS-GNL](https://github.com/Mazoise/42TESTERS-GNL) by [Mazoise](https://github.com/Mazoise)

![results](https://github.com/Freya-Tenebrae/Get_next_line/blob/main/42TESTERS-GNL.png)

> [gnl-war-machine-v2019](https://github.com/C4r4c0l3/gnl-war-machine-v2019) by [C4r4c0l3](https://github.com/C4r4c0l3)

![results](https://github.com/Freya-Tenebrae/Get_next_line/blob/main/gnl-war-machine-v2019.png)

> [Get_Next_Line_Tester](https://github.com/Hellio404/Get_Next_Line_Tester) by [Hellio404](https://github.com/Hellio404)

![results](https://github.com/Freya-Tenebrae/Get_next_line/blob/main/Get_Next_Line_Tester.png)

> [gnlTester](https://github.com/Tripouille/gnlTester) by [Tripouille](https://github.com/Tripouille)

![results](https://github.com/Freya-Tenebrae/Get_next_line/blob/main/gnlTester1.png)
![results](https://github.com/Freya-Tenebrae/Get_next_line/blob/main/gnlTester2.png)
