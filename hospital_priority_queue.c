#include <stdio.h>
#include <stdlib.h>

void printArray(const int a[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void maxHeapInsert(int heap[], int *size, int value) {
    int i = (*size)++;
    heap[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] >= heap[i])
            break;

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

void showHeapInsertions(const int input[], int n) {
    int *heap = malloc(n * sizeof(int));
    if (heap == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    int size = 0;

    printf("\n--- MAX HEAP INSERTION ---\n");

    for (int i = 0; i < n; i++) {
        maxHeapInsert(heap, &size, input[i]);
        printf("After inserting %d: ", input[i]);
        printArray(heap, size);
    }

    printf("Final Max Heap: ");
    printArray(heap, size);

    free(heap);
}

void heapify(int a[], int n, int root, long *comparisons, long *swaps) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n) {
        (*comparisons)++;
        if (a[left] > a[largest])
            largest = left;
    }

    if (right < n) {
        (*comparisons)++;
        if (a[right] > a[largest])
            largest = right;
    }

    if (largest != root) {
        int temp = a[root];
        a[root] = a[largest];
        a[largest] = temp;
        (*swaps)++;

        heapify(a, n, largest, comparisons, swaps);
    }
}

void heapSort(int a[], int n, long *comparisons, long *swaps) {
    *comparisons = 0;
    *swaps = 0;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, comparisons, swaps);

    printf("\n--- HEAP SORT ---\n");
    printf("Initial Max Heap: ");
    printArray(a, n);

    for (int end = n - 1; end > 0; end--) {
        int temp = a[0];
        a[0] = a[end];
        a[end] = temp;
        (*swaps)++;

        heapify(a, end, 0, comparisons, swaps);

        printf("After placing %d: ", a[end]);
        printArray(a, n);
    }
}

int partition(int a[], int low, int high, long *comparisons, long *swaps) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        (*comparisons)++;

        if (a[j] <= pivot) {
            i++;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            (*swaps)++;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    (*swaps)++;

    printf("Partition [%d-%d], Pivot %d: ", low, high, pivot);
    printArray(a, high + 1);

    return i + 1;
}

void quickSort(int a[], int low, int high,
               long *comparisons, long *swaps) {
    if (low < high) {
        int p = partition(a, low, high, comparisons, swaps);
        quickSort(a, low, p - 1, comparisons, swaps);
        quickSort(a, p + 1, high, comparisons, swaps);
    }
}

int main(void) {
    int input[] = {45, 72, 30, 90, 65, 50, 85};
    int n = sizeof(input) / sizeof(input[0]);

    int *heapData = malloc(n * sizeof(int));
    int *quickData = malloc(n * sizeof(int));

    if (heapData == NULL || quickData == NULL) {
        printf("Memory allocation failed.\n");
        free(heapData);
        free(quickData);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        heapData[i] = input[i];
        quickData[i] = input[i];
    }

    printf("=== HOSPITAL PATIENT PRIORITY QUEUE ===\n");
    printf("Input severity scores: ");
    printArray(input, n);

    showHeapInsertions(input, n);

    long heapComparisons, heapSwaps;
    heapSort(heapData, n, &heapComparisons, &heapSwaps);

    printf("Final Heap Sort output: ");
    printArray(heapData, n);
    printf("Heap Sort comparisons: %ld\n", heapComparisons);
    printf("Heap Sort swaps: %ld\n", heapSwaps);

    long quickComparisons = 0, quickSwaps = 0;

    printf("\n--- QUICK SORT ---\n");
    quickSort(quickData, 0, n - 1,
              &quickComparisons, &quickSwaps);

    printf("Final Quick Sort output: ");
    printArray(quickData, n);
    printf("Quick Sort comparisons: %ld\n", quickComparisons);
    printf("Quick Sort swaps: %ld\n", quickSwaps);

    free(heapData);
    free(quickData);

    return 0;
}
