#include "../sorting.h"

// ===================== BUBBLE SORT =====================
static void doBubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            addStep(STEP_COMPARE, j, j + 1);
            if (sortLess(arr[j + 1], arr[j])) {
                addStep(STEP_SWAP, j, j + 1);
                swapElements(arr, j, j + 1);
                swapped = true;
            }
        }
        addStep(STEP_SORTED, n - 1 - i, -1);
        if (!swapped) break;
    }
    addStep(STEP_SORTED, 0, -1);
}
