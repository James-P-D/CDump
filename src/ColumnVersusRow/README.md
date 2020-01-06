# ColumnVersusRow
Quick test for Column vs. Row array iteration in C

## Introduction

If we are given a two-dimensional array of bytes and need to increment every value, does it matter if the outer `for` loop is for the row or column index?

By row first:
```C
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            array[row][column]++;
        }
    }
```

By column first:
```C
    for (int column = 0; column < COLUMNS; column++) {
        for (int row = 0; row < ROWS; row++) {
            array[row][column]++;
        }
    }
```

On most modern architecture, the answer is actually **yes**.

![Screenshot](https://github.com/James-P-D/BranchPrediction/blob/master/Screenshot.png)