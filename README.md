# push_swap

A project from 42 that sorts a stack of integers using a limited set of operations and a second auxiliary stack.

## 🚀 Usage

Clone the repository and compile:

```bash
make
```

Run the program with a list of numbers:

```bash
./push_swap 2 1 3 6 5 8
```

It will output the sequence of moves needed to sort the stack.

You can also pass the numbers as a single string:

```bash
./push_swap "2 1 3 6 5 8"
```

Or a combination of both:

```bash
./push_swap "2 1 3 6 5 8" 25 21 28 "35 -3"
```

## 🧪 Checking the result

You can verify the moves with the checker:

```bash
./push_swap 2 1 3 6 5 8 | ./checker_linux 2 1 3 6 5 8
```

If everything is correct, it will print:

```
OK
```

otherwise:

```
KO
```

## 🛠️ Features

- Handles input as separate arguments or a single string
- Uses radix sort for efficient sorting
- Optimizes output by cleaning unnecessary moves

---
