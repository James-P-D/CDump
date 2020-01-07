# ForLoopOptimisation
Quick test for for-loop optimisation in C

## Introduction

If we are given a large array of integers and wish to traverse it, does the direction we traverse make a difference?

```C
	for (int i = 0; i < SIZE; i++) {
		array[i]++;
	}
```

..or..

```C
	for (int i = SIZE - 1; i >= 0; i--) {
		array[i]++;
	}
```

On most modern architecture, the answer is actually **yes**.

![Screenshot](https://github.com/James-P-D/CDump/blob/master/src/ForLoopOptimisation/Screenshot.png)