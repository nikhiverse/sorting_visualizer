#include "../sorting.h"

// ===================== SHELL SORT =====================
static void doShellSort(int* arr, int n) {
    // Use Knuth's gap sequence: 1, 4, 13, 40, ...
    int gap = 1;
    while (gap < n / 3) {
        gap = gap * 3 + 1;
    }

    while (gap >= 1) {
        for (int i = gap; i < n; i++) {
            int j = i;
            while (j >= gap) {
                addStep(STEP_COMPARE, j - gap, j);
                if (sortLess(arr[j], arr[j - gap])) {
                    addStep(STEP_SWAP, j - gap, j);
                    swapElements(arr, j - gap, j);
                    j -= gap;
                } else {
                    break;
                }
            }
        }
        gap /= 3;
    }
}
