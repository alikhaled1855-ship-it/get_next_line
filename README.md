# Get Next Line

*This project has been created as part of the 42 curriculum by alsaleh*

## Description

Get Next Line is a function that reads a line from a file descriptor. It allows you to read text files line by line, which is very useful for file processing in C.

The function returns one line at a time, including the newline character `\n` (except for the last line if it doesn't end with `\n`).

## Instructions

### Compilation

Compile the project with your files:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_file.c
```

You can change `BUFFER_SIZE` to any value (1, 42, 10000, etc.).

### Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithm

The function uses a **static buffer** to store leftover data between calls. Here's how it works:

1. **Read from file** - Read chunks of BUFFER_SIZE bytes until we find a newline `\n` or reach end of file
2. **Extract line** - Take everything up to and including the `\n`
3. **Update buffer** - Keep remaining data for the next call

### Key Features:
- **Static variable**: Remembers leftover data between function calls
- **Dynamic buffer**: Joins read chunks until a complete line is found
- **Memory efficient**: Only reads what's needed

### Helper Functions:
- `ft_strlen` - Gets string length
- `ft_strchr` - Finds character in string
- `ft_strlcpy` - Copies string safely with null termination
- `ft_strjoin` - Joins two strings together

## Resources

### Documentation
- [Linux man pages - read()](https://man7.org/linux/man-pages/man2/read.2.html)
- [Static variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)

### AI Usage
AI was not used in this project. The code was developed through:
- Reading the subject requirements
- Understanding static variables concept
- Manual coding and debugging
- Peer discussions and testing