# `get_next_line`

A custom function to read a file descriptor line by line  
**Project validated with a total score of 125% (mandatory + bonus)**

---

## 📖 About

`get_next_line` is a fundamental 42 project focused on low-level file handling in C.  
It challenges students to implement a function that returns one line at a time from a file descriptor — managing memory, buffer reading, and file state.

The bonus part extends the challenge to support **multiple file descriptors simultaneously**, pushing your ability to manage state and modular code in C.

---

## 🛠️ Skills Gained

- File descriptor reading with `read()`
- Dynamic memory allocation (`malloc`, `free`)
- Handling static variables and memory scope
- Manual string manipulation and concatenation
- Managing multiple FDs with static arrays (bonus)
- Clean modular code structure under Norminette

---

## ✅ Project Features

| Feature                     | Description                                           |
|----------------------------|-------------------------------------------------------|
| `get_next_line`            | Returns a single line from a file descriptor          |
| Buffered reading           | Uses `read()` in chunks of `BUFFER_SIZE`              |
| Persistent storage         | Static `stash` preserves leftover buffer data         |
| Bonus: multi-FD support    | Uses indexed static storage per FD                    |
| Norminette compliant       | 100% format and structure adherence                   |

---

## 🧪 Usage

To test the function:

1. Compile the files manually:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

2. Run with a test file:

```bash
./a.out < file.txt
```

For the bonus version (multi-FD support):

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

---

## 📌 Notes

- Written in C with full Norminette compliance
- Only allowed functions used: `read`, `malloc`, `free`
- Handles files and standard input (stdin)
- Fully leak-free and tested with Valgrind
- Bonus version supports reading from multiple files simultaneously

---

## 👤 Author

**Mykyta Ivanov**  
Student @ 42 Lisboa  
GitHub: [@myivanov-c](https://github.com/myivanov-c)

---

## ✅ Project Status

- Completed (mandatory + bonus)
- Fully tested and validated
- **Scored 125%**
