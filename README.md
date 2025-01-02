## C Sudoku Solver

This is a Sudoku solver program written in C. It reads a Sudoku puzzle from a text file named `puzzle.txt` and prints the solved puzzle to the console. 

I apologize for the somewhat cryptic variable names. Let's just say I was channeling my inner coding Zen master, and 'meaningful identifiers' were not exactly top of mind at the time.

### Features

  * Solves Sudoku puzzles using backtracking algorithm.
  * Reads input from a text file (`puzzle.txt`).
  * Prints the solved puzzle to the console.

### Getting Started

**Prerequisites:**

  * A C compiler (e.g., GCC)
  * Basic understanding of C programming

**Building and Running:**

1.  Clone this repository:

    ```bash
    git clone https://github.com/ertekin/sudoku.git
    ```

2.  Navigate to the project directory:

    ```bash
    cd sudoku
    ```

3.  Compile the program:

    ```bash
    gcc sudoku_solver.c -o sudoku_solver
    ```

4.  Prepare your Sudoku puzzle:

      * Create a text file named `puzzle.txt`.
      * Read the puzzle you want to solve from top-left to the bottom-right and put the numbers in one line.
      * Use numbers `1-9` to represent filled cells and `-` for empty cells.

5.  Run the program:

    ```bash
    ./sudoku_solver
    ```
    This will read the puzzle from `puzzle.txt`, solve it, and print the solution to the console.

### Example Usage

**puzzle.txt:**

For the sample puzzle below:
```
┌───────┬───────┬───────┐
│ 5 3 - │ - 7 - │ - - - │
│ 6 - - │ 1 9 5 │ - - - │
│ - 9 8 │ - - - │ - 6 - │
├───────┼───────┼───────┤
│ 8 - - │ - 6 - │ - - 3 │
│ 4 - - │ 8 - 3 │ - - 1 │
│ 7 - - │ - 2 - │ - - 6 │
├───────┼───────┼───────┤
│ - 6 - │ - - - │ 2 8 - │
│ - - - │ 4 1 9 │ - - 5 │
│ - - - │ - 8 - │ - 7 9 │
└───────┴───────┴───────┘
```
The `puzzle.txt` should read all the digits in one line like below.
```
53--7----6--195----98----6-8---6---34--8-3--17---2---6-6----28----419--5----8--79
```

**Output:**

```
-----------------
5|3|4|6|7|8|9|1|2|
-----------------
6|7|2|1|9|5|3|4|8|
-----------------
1|9|8|3|4|2|5|6|7|
-----------------
8|5|9|7|6|1|4|2|3|
-----------------
4|2|6|8|5|3|7|9|1|
-----------------
7|1|3|9|2|4|8|5|6|
-----------------
9|6|1|5|3|7|2|8|4|
-----------------
2|8|7|4|1|9|6|3|5|
-----------------
3|4|5|2|8|6|1|7|9|
-----------------

Number of attempts: 6

```
As you see, I did not format the output yet. AI-like animation would be good for the next version 🎯

### Contributing

Feel free to contribute to this project by:

  * Reporting bugs
  * Suggesting improvements
  * Submitting pull requests with new features

### License

This project is licensed under the [MIT License](https://www.google.com/url?sa=E&source=gmail&q=https://opensource.org/licenses/MIT).
