# Data Structures and Algorithms – Assignment 2

## Question 10

A logistics company receives package weights:

**20, 15, 20, 10, 15, 20, 25, 10**

Each package has a unique package ID.

---

## (a) Merge Sort and Quick Sort

The package weights are sorted using:

1. Merge Sort
2. Quick Sort

### Input Data

| Package ID | Weight |
|---|---:|
| P1 | 20 |
| P2 | 15 |
| P3 | 20 |
| P4 | 10 |
| P5 | 15 |
| P6 | 20 |
| P7 | 25 |
| P8 | 10 |

### Original Order

```text
P1(20) P2(15) P3(20) P4(10)
P5(15) P6(20) P7(25) P8(10)
```

### Merge Sort

The program records the important intermediate merge steps during execution.

Final sorted result:

```text
P4(10) P8(10) P2(15) P5(15)
P1(20) P3(20) P6(20) P7(25)
```

### Quick Sort

The program records the important partition steps during execution.

Final sorted result:

```text
P4(10) P8(10) P2(15) P5(15)
P1(20) P3(20) P6(20) P7(25)
```

---

## (b) Stability of Sorting

The input contains duplicate weights.

The original order of packages having the same weight is:

```text
Weight 10 : P4, P8
Weight 15 : P2, P5
Weight 20 : P1, P3, P6
```

After sorting, the order remains:

```text
Weight 10 : P4, P8
Weight 15 : P2, P5
Weight 20 : P1, P3, P6
```

Therefore, the original relative order of packages with equal weights is preserved.

The program verifies this using the package IDs and their original positions.

---

## (c) Analysis

### Duplicate Values

The input contains duplicate weights:

- 10 occurs twice
- 15 occurs twice
- 20 occurs three times

The package IDs are used to distinguish packages having the same weight.

### Stability

A sorting algorithm is stable when elements having equal keys retain their original relative order.

For this problem:

```text
P4(10) before P8(10)
P2(15) before P5(15)
P1(20) before P3(20) before P6(20)
```

The modified sorting implementation preserves these orders.

### Number of Comparisons

The C program counts the comparisons performed by both sorting algorithms.

| Algorithm | Number of Comparisons |
|---|---:|
| Merge Sort | 16 |
| Quick Sort | 18 |

The actual values are taken from the execution of `main.c`.

---

## Time Complexity

| Algorithm | Best Case | Average Case | Worst Case |
|---|---|---|---|
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |

---

## Space Complexity

| Algorithm | Space Complexity |
|---|---|
| Merge Sort | O(n) |
| Quick Sort | O(log n) average, O(n) worst case |

---

## Comparison

| Feature | Merge Sort | Quick Sort |
|---|---|---|
| Duplicate values | Handles duplicates | Handles duplicates |
| Stability | Stable | Modified to preserve equal-item order |
| Best Case | O(n log n) | O(n log n) |
| Average Case | O(n log n) | O(n log n) |
| Worst Case | O(n log n) | O(n²) |
| Extra Space | O(n) | O(log n) average |

---

## Conclusion

Both Merge Sort and Quick Sort successfully sort the package weights.

The package IDs are used to verify the relative order of packages with equal weights. The modified implementations preserve the original order of equal-weight packages.

Merge Sort has O(n log n) worst-case time complexity, while Quick Sort can have O(n²) worst-case time complexity depending on the partitioning.

The detailed execution results and comparison counts are available in `output.txt`.

---

## Files

```text
README.md    - Problem, analysis and conclusion
main.c       - C implementation
output.txt   - Program execution output
```
