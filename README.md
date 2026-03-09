# 📂 File Handling in C — Tasks

## Mini-Task 1: The Basic "Echo"

**Task:**

Create a text file named `test.txt` with 3 lines of text.  
Write a program that opens the file and prints each line to the console with a line number prefix (e.g., `1: Hello World`).

**Compile & Run**

```bash
cd mini_tasks
gcc task1.c -o test1 && ./test1
```

---

## Mini-Task 2: The "Rewind" Mechanic

**Task:**

Read the first line of a file using `fgets` and print it.  
Then use `fseek` to move the file pointer back to the start of the file and read the same line again.

**Compile & Run**

```bash
cd mini_tasks
gcc task2.c -o test2 && ./test2
```

---

## Mini-Task 3: Selective Writing

**Task:**

Open an existing file for reading and a new file (`output.txt`) for writing.  
Read the existing file line-by-line and only write lines to the new file if they do **not** contain the letter `X`.

**Compile & Run**

```bash
cd mini_tasks
gcc task3.c -o test3 && ./test3
```

---

# 📑 Main Task: File Comparison & Merge Tool

## Task

Create a C program that compares two text files **line-by-line** and allows the user to merge differences.

The program should:

- Take two file paths as command-line arguments.
- Open both files for reading using `fopen`.
- Create a temporary output file for the merged result.
- Read lines from both files using `fgets`.
- If the lines are identical, automatically write the line to the output file.
- If the lines are different, display both lines and ask the user which one to keep.
- Write the chosen line to the output file using `fputs`.
- Use `fseek` and `ftell` when needed to manage file pointer positions.
- Close all files using `fclose`.

**Compile & Run**

```bash
cd file_handling_in_c
gcc task.c -o test
./test test1.txt test2.txt
```