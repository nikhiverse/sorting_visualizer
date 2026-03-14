#include "../sorting.h"

// ===================== INSERTION SORT =====================
static void doInsertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0) {
            addStep(STEP_COMPARE, j - 1, j);
            if (sortLess(arr[j], arr[j - 1])) {
                addStep(STEP_SWAP, j - 1, j);
                swapElements(arr, j - 1, j);
                j--;
            } else {
                break;
            }
        }
    }
}
