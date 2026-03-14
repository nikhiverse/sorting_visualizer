#include "../sorting.h"

// ===================== QUICK SORT =====================
static void doQuickSort(int* arr, int low, int high) {
    if (low >= high) {
        if (low == high) {
            addStep(STEP_SORTED, low, -1);
        }
        return;
    }

    addStep(STEP_PIVOT, low, -1);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        addStep(STEP_COMPARE, j, high);
        if (sortLessEq(arr[j], pivot)) {
            i++;
            if (i != j) {
                addStep(STEP_SWAP, i, j);
                swapElements(arr, i, j);
            }
        }
    }

    i++;
    if (i != high) {
        addStep(STEP_SWAP, i, high);
        swapElements(arr, i, high);
    }
    addStep(STEP_SORTED, i, -1);

    doQuickSort(arr, low, i - 1);
    doQuickSort(arr, i + 1, high);
}
