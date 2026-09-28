# Hospital Priority Queue using Max Heap and Sorting

Implementation and comparison of Max Heap, Heap Sort and Quick Sort in C for managing hospital patients according to severity.

# Hospital Priority Queue using Max Heap and Sorting

## Problem Statement

A hospital uses a priority queue to manage patients according to severity. A higher severity score represents a higher priority.

Patient severity scores:

`45, 72, 30, 90, 65, 50, 85`

The objective is to:

1. Implement a Max Heap and insert the above patient severity scores.
2. Implement Heap Sort and Quick Sort for the same data.
3. Record important intermediate steps and final output.
4. Compare the approaches based on heap structure, comparisons/swaps, time complexity and space requirements.
5. Determine the suitable approach when patients are continuously inserted and the highest-priority patient is needed immediately.

---

# Source Code

## Files Included

- `hospital_priority_queue.c`

---

# Input Data

```text
45 72 30 90 65 50 85
```

Higher severity score = higher priority.

---

# Execution Results

## Max Heap Insertion

### Important Heap States

After inserting 45:

```text
45
```

After inserting 72:

```text
72 45
```

After inserting 30:

```text
72 45 30
```

After inserting 90:

```text
90 72 30 45
```

After inserting 65:

```text
90 72 30 45 65
```

After inserting 50:

```text
90 72 50 45 65 30
```

After inserting 85:

```text
90 72 85 45 65 30 50
```

Final Max Heap:

```text
90 72 85 45 65 30 50
```

Heap representation:

```text
        90
       /  \
     72    85
    / \    / \
   45 65  30 50
```

Heap height = `floor(log2(7)) = 2`

---

# Heap Sort

### Important Steps

Initial Max Heap:

```text
90 72 85 45 65 50 30
```

After extracting 90:

```text
85 72 50 45 65 30 90
```

After extracting 85:

```text
72 65 50 45 30 85 90
```

After extracting 72:

```text
65 45 50 30 72 85 90
```

After extracting 65:

```text
50 45 30 65 72 85 90
```

After extracting 50:

```text
45 30 50 65 72 85 90
```

After extracting 45:

```text
30 45 50 65 72 85 90
```

Final Heap Sort Output:

```text
30 45 50 65 72 85 90
```

Comparisons = 21

Swaps = 18

> The comparison and swap counts are specific to the implementation and this input.

---

# Quick Sort

The Quick Sort implementation uses the last element as the pivot.

### Important Partition Steps

### Step 1

Pivot = 85

```text
45 72 30 65 50 85 90
```

### Step 2

Pivot = 50

```text
45 30 50 65 72 85 90
```

### Step 3

Pivot = 30

```text
30 45 50 65 72 85 90
```

### Step 4

Pivot = 72

```text
30 45 50 65 72 85 90
```

Final Quick Sort Output:

```text
30 45 50 65 72 85 90
```

Comparisons = 12

Swaps = 12

> The comparison and swap counts are specific to the implementation and this input.

---

# Performance Comparison

| Parameter | Max Heap / Heap Sort | Quick Sort |
|---|---|---|
| Heap Structure | Complete Binary Max Heap | No heap |
| Heap Size | 7 | N/A |
| Heap Height | 2 | N/A |
| Observed Comparisons | 21 | 12 |
| Observed Swaps | 18 | 12 |
| Best-Case Time | O(n log n) | O(n log n) |
| Average-Case Time | O(n log n) | O(n log n) |
| Worst-Case Time | O(n log n) | O(n²) |
| Auxiliary Space | O(1)* | O(log n) average |
| Suitable for Dynamic Priority Queue | Yes | No |

`*` Heap Sort uses O(1) auxiliary array space; the recursive heapify implementation uses O(log n) call-stack depth.

---

# Complexity Analysis

## Max Heap

### Time Complexity

Insertion:

```text
O(log n)
```

Explanation:

- A new patient is inserted at the end of the heap.
- It may move upward toward the root.
- The height of a binary heap is O(log n).

Highest-priority patient:

```text
O(1)
```

The maximum severity is always stored at the root.

Removing the highest-priority patient:

```text
O(log n)
```

---

## Heap Sort

### Time Complexity

```text
Best Case    = O(n log n)
Average Case = O(n log n)
Worst Case   = O(n log n)
```

Heap Sort maintains the same asymptotic running time regardless of the initial arrangement.

### Space Complexity

```text
O(1)
```

for the array-based Heap Sort apart from the recursion stack used by the `heapify` function.

---

## Quick Sort

### Time Complexity

```text
Best Case    = O(n log n)
Average Case = O(n log n)
Worst Case   = O(n²)
```

The worst case can occur when the selected pivot repeatedly creates highly unbalanced partitions.

### Space Complexity

```text
O(log n)
```

on average because of recursive function calls.

---

# Dynamic Priority Queue Analysis

The hospital continuously receives new patients and needs the highest-priority patient immediately.

For a Max Heap:

| Operation | Time Complexity |
|---|---:|
| Insert patient | O(log n) |
| View highest priority | O(1) |
| Remove highest priority | O(log n) |

The maximum severity score is always available at the root.

For example:

```text
        90
       /  \
     72    85
    / \    / \
   45 65  30 50
```

The patient with severity `90` can be accessed immediately without sorting all patients.

---

# Conclusion

For the given input:

```text
45 72 30 90 65 50 85
```

both Heap Sort and Quick Sort produce:

```text
30 45 50 65 72 85 90
```

For this implementation and input, Heap Sort required 21 counted comparisons and 18 swaps, while Quick Sort required 12 counted comparisons and 12 swaps. These observed counts depend on the implementation and input.

For a continuously changing hospital priority queue, a Max Heap is suitable because the highest-priority patient is always maintained at the root. A new patient can be inserted in `O(log n)`, the highest-priority patient can be viewed in `O(1)`, and removing it takes `O(log n)`.

Therefore, the Max Heap is appropriate for the hospital's **dynamic priority queue**, while Heap Sort and Quick Sort are useful when a complete sorted list of patients is required.
