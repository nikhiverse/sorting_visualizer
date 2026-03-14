#include "../sorting.h"

// ===================== HEAP SORT =====================
static void siftDown(int* arr, int start, int end) {
    int root = start;
    while (root * 2 + 1 <= end) {
        int child = root * 2 + 1;
        int toSwap = root;

        addStep(STEP_COMPARE, toSwap, child);
        if (sortLess(arr[toSwap], arr[child])) {
            toSwap = child;
        }
        if (child + 1 <= end) {
            addStep(STEP_COMPARE, toSwap, child + 1);
            if (sortLess(arr[toSwap], arr[child + 1])) {
                toSwap = child + 1;
            }
        }
        if (toSwap == root) {
            return;
        }
        addStep(STEP_SWAP, root, toSwap);
        swapElements(arr, root, toSwap);
        root = toSwap;
    }
}

static void doHeapSort(int* arr, int n) {
    // Build max heap
    for (int start = (n - 2) / 2; start >= 0; start--) {
        siftDown(arr, start, n - 1);
    }

    // Extract elements
    for (int end = n - 1; end > 0; end--) {
        addStep(STEP_SWAP, 0, end);
        swapElements(arr, 0, end);
        addStep(STEP_SORTED, end, -1);
        siftDown(arr, 0, end - 1);
    }
    addStep(STEP_SORTED, 0, -1);
}
