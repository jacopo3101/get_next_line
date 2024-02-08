# Get_next_line

## Score
![project score](/assets/score.png)

## Overview
This project focuses on implementing a function called get_next_line in C, which reads a line from a file descriptor (`fd`). The function allows reading text files line by line, facilitating file input processing.
```c
char *get_next_line(int fd);
```

## Mandatory Part
### Features
- Reads a line from a file descriptor, returning it as a string.
- Dynamic buffer size allocation based on the input file.
### Instructions
This will compile the source files and generate an executable.

To compile with a specific buffer size (e.g., 42):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```
### Usage
```c
#include "get_next_line.h"

int main(void) {
    int fd;
    char *line;

    // Open file descriptor (fd) or use standard input (STDIN_FILENO)
    fd = open("example.txt", O_RDONLY);
    // Loop to read lines until EOF or error
    while ((line = get_next_line(fd)) != NULL) {
        // Process line
        printf("%s\n", line);
        // Free dynamically allocated memory for line
        free(line);
    }
    // Close file descriptor
    close(fd);
    return (0);
}
```

## Bonus Part
### Features
- Handles multiple file descriptors simultaneously.
- Implements get_next_line using only one static variable.