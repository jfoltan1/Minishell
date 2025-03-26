# Minishell - As beautiful as a shell

A basic shell implemented in C, recreating key bash behavior with a clean and functional structure. This is a hands-on project that deep-dives into processes, file descriptors, signals, and terminal handling.

---

## 🧠 What It Does

- Displays a working shell prompt
- Parses and executes commands
- Handles redirections and pipes
- Expands environment variables
- Implements core bash built-ins
- Manages signals like `Ctrl+C`, `Ctrl+D`, and `Ctrl+\`

---

## ⚙️ How to Run

```bash
make
./minishell
```

---

## 📦 Features

- ✅ Command parsing with quotes and variables
- ✅ Built-ins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- ✅ Redirections: `<`, `>`, `>>`, `<<`
- ✅ Pipe `|` support
- ✅ Variable expansion (`$VAR`, `$?`)
- ✅ Clean signal handling
- ✅ Uses readline for input/history

---

## 🧰 Tech Stack

- Language: C (Norm compliant)
- Input: `readline` library
- Process mgmt: `fork`, `execve`, `pipe`, etc.
- Build: `Makefile`
- Utilities: `libft`, custom ft_printf

---

## 🏗️ Room for Improvements

- [ ] Improve syntax error handling
- [ ] Quote parsing edge cases
- [ ] Custom history saving/loading
- [ ] Job control and background processes
- [ ] Improved signal edge handling

---

## ⚠️ Known Limitations

- Only one global variable is allowed (signal-related)
- Limited to what the subject describes (no `;`, `\`, etc.)
- Readline leaks aren't fixed (allowed)
- Behavior based on bash, but not 100% bash

---

## ✅ Bonus Goals (Only if mandatory is perfect)

- `&&` and `||` logic operations
- Wildcards `*` matching current dir contents
- Grouping with parentheses

---

## 🧪 Testing Tips

- Use bash to compare behavior
- Use `valgrind` to ensure your own code is leak-free:
```bash
valgrind ./minishell
```

---

## 🗂️ Project Structure

```
├── src/
├── includes/
├── libft/
├── Makefile
└── README.md
```

---

## 💬 Final Note

This project gives real insight into how shells work under the hood. It touches processes, file descriptors, signal handling, and terminal interaction. Building your own `bash` is one of the best ways to level up your C and system programming skills.

---
