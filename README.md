# 📚 Get Next Line

![42 Badge](https://img.shields.io/badge/42-Get_Next_Line-darkgreen)
![C Badge](https://img.shields.io/badge/Language-C-blue)
![Status Badge](https://img.shields.io/badge/Status-Completed-success)

> Reading a line from a file descriptor is far too tedious...

## 🔍 Overview

This project implements a function called `get_next_line()` that reads and returns a line from a file descriptor. It's a crucial utility for any serious C programming project that deals with file I/O, and it teaches important concepts like static variables, dynamic memory allocation, and file descriptor management.

## 🧩 Function Description

```c
char *get_next_line(int fd);
```

### Parameters
- `fd`: The file descriptor to read from

### Return Value
- A new allocated string containing the line that was read
- `NULL` if there is nothing else to read or if an error occurred

## ⚙️ Key Features

- **Line by Line Reading**: The function returns one line at a time with each call
- **Proper Memory Management**: All allocated memory is properly freed to prevent leaks
- **Buffer Size Flexibility**: Works with any buffer size defined during compilation
- **File Descriptor Support**: Works with standard input, files, and other valid file descriptors
- **Terminating Character Handling**: Properly handles newline characters in the returned strings
- **Bonus Implementation**: Supports reading from multiple file descriptors simultaneously

## 🛠️ Implementation Details

The project is divided into the following files:

### Core Files (Mandatory Part)
- `get_next_line.c`: Main function implementation
- `get_next_line_utils.c`: Helper functions for string manipulation
- `get_next_line.h`: Header file with function prototypes

### Bonus Files
- `get_next_line_bonus.c`: Enhanced implementation supporting multiple file descriptors
- `get_next_line_utils_bonus.c`: Helper functions for the bonus part
- `get_next_line_bonus.h`: Header file for the bonus implementation

## 🔄 How It Works

The implementation follows these key steps:

1. **Line Checking**: The `line_check()` function searches for newline characters in the current buffer
2. **Line Extraction**: When a newline is found, `print_line()` extracts and returns the line
3. **Buffer Management**: The function reads from the file descriptor in chunks defined by `BUFFER_SIZE`
4. **Memory Management**: All operations ensure proper memory allocation and deallocation with `_free()`
5. **State Persistence**: Uses static variables to maintain the reading state between function calls

## 💡 Key Functions

- `line_check()`: Checks if a newline character exists in the current buffer
- `print_line()`: Extracts and returns a line up to a newline character
- `_free()`: Manages memory deallocation to prevent leaks
- `ft_substr()`: Creates a substring from a given string
- `ft_strjoin()`: Concatenates two strings
- `ft_strlen()`: Calculates the length of a string

## 📋 Usage

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_program.c
```

You can adjust the `BUFFER_SIZE` value to optimize performance for your specific use case.

### Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    // Open a file
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    // Read the file line by line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    // Close the file
    close(fd);
    return (0);
}
```

### Using the Bonus Implementation

To use the bonus implementation that supports multiple file descriptors:

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2;
    char *line;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);

    // Alternating reads between two files
    line = get_next_line(fd1);
    printf("File 1: %s", line);
    free(line);

    line = get_next_line(fd2);
    printf("File 2: %s", line);
    free(line);

    // Continue reading...

    close(fd1);
    close(fd2);
    return (0);
}
```

## 🔗 What I Learned

- **Static Variables**: Understanding persistence between function calls
- **File I/O**: Working with file descriptors and the `read()` system call
- **Memory Management**: Proper allocation and deallocation to prevent leaks
- **Buffer Handling**: Techniques for efficient reading and processing
- **Data Structures**: Using strings and buffers effectively

## ⚠️ Limitations

- The function exhibits undefined behavior if the file is modified between calls
- Binary files may not be processed correctly
- Very large buffer sizes might cause memory issues
- Performance depends on the chosen buffer size

## 📝 License

This project is part of the 1337 School curriculum and is provided for educational purposes.

---

Made with ❤️ by yoelansa @ 1337
