

#include <stdio.h>

#define N 8

typedef struct
{
    char id[5];
    int weight;
    int position;
} Package;

int mergeComparisons = 0;
int quickComparisons = 0;

void display(Package a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%s(%d) ", a[i].id, a[i].weight);

    printf("\n");
}

/* Merge Sort */

void merge(Package a[], int low, int mid, int high)
{
    Package temp[N];

    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        mergeComparisons++;

        if (a[i].weight <= a[j].weight)
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
        a[i] = temp[i];

    printf("Merge: ");
    display(a + low, high - low + 1);
}

void mergeSort(Package a[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

/* Quick Sort */

int before(Package a, Package b)
{
    quickComparisons++;

    if (a.weight < b.weight)
        return 1;

    if (a.weight > b.weight)
        return 0;

    return a.position < b.position;
}

int partition(Package a[], int low, int high)
{
    Package pivot = a[high];
    Package temp;

    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (before(a[j], pivot))
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    printf("Partition: ");
    display(a + low, high - low + 1);

    return i + 1;
}

void quickSort(Package a[], int low, int high)
{
    int p;

    if (low < high)
    {
        p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

/* Check stability */

void checkStability(Package a[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i].weight == a[j].weight &&
                a[i].position > a[j].position)
            {
                printf("Not Stable\n");
                return;
            }
        }
    }

    printf("Stable\n");
}

int main()
{
    Package data[N] =
    {
        {"P1", 20, 0},
        {"P2", 15, 1},
        {"P3", 20, 2},
        {"P4", 10, 3},
        {"P5", 15, 4},
        {"P6", 20, 5},
        {"P7", 25, 6},
        {"P8", 10, 7}
    };

    Package mergeArray[N];
    Package quickArray[N];

    int i;

    for (i = 0; i < N; i++)
    {
        mergeArray[i] = data[i];
        quickArray[i] = data[i];
    }

    printf("Original Data:\n");
    display(data, N);

    printf("\nMerge Sort:\n");
    mergeSort(mergeArray, 0, N - 1);

    printf("\nFinal Merge Sort Result:\n");
    display(mergeArray, N);

    printf("Comparisons: %d\n", mergeComparisons);
    printf("Stability: ");
    checkStability(mergeArray, N);

    printf("\nQuick Sort:\n");
    quickSort(quickArray, 0, N - 1);

    printf("\nFinal Quick Sort Result:\n");
    display(quickArray, N);

    printf("Comparisons: %d\n", quickComparisons);
    printf("Stability: ");
    checkStability(quickArray, N);

    return 0;
}
