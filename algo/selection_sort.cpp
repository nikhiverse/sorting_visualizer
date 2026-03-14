#include "../sorting.h"

// ===================== SELECTION SORT =====================
static void doSelectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            addStep(STEP_COMPARE, minIdx, j);
            if (sortLess(arr[j], arr[minIdx])) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            addStep(STEP_SWAP, i, minIdx);
            swapElements(arr, i, minIdx);
        }
        addStep(STEP_SORTED, i, -1);
    }
    addStep(STEP_SORTED, n - 1, -1);
}
