#include "../sorting.h"

// ===================== MERGE SORT =====================

// We use an in-place merge since the visualization uses STEP_SWAP 
// which physically animates elements swapping places. Standard merge
// sort overwrites values, mapping poorly to this visualizer.
static void doMergeSort(int* arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    doMergeSort(arr, left, mid);
    doMergeSort(arr, mid + 1, right);

    int i = left;
    int j = mid + 1;

    if (sortLessEq(arr[mid], arr[j])) {
        addStep(STEP_COMPARE, mid, j);
        return;
    }

    while (i <= mid && j <= right) {
        addStep(STEP_COMPARE, i, j);

        if (sortLessEq(arr[i], arr[j])) {
            i++;
        } else {
            int index = j;

            // Shift element j down to position i using swaps
            while (index > i) {
                swapElements(arr, index, index - 1);
                addStep(STEP_SWAP, index, index - 1);
                index--;
            }

            i++;
            mid++;
            j++;
        }
    }
}
