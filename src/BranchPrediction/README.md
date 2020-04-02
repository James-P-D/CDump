# BranchPrediction
Quick test for Branch Prediction in C

## Introduction

If we are given a large array of integers and calculate the number of positive, negative and zero values in the array, does whether the array is sorted or not influence the time taken for the calculation?

```C
    for (int i = 0; i < SIZE; i++) {
        if (array[i] > 0) positive++;
        else if (array[i] < 0) negative++;
        else zero++;
    }    
```

On most modern architecture, the answer is actually **yes**.

![Screenshot](https://github.com/James-P-D/CDump/blob/master/src/BranchPrediction/Screenshot.png)