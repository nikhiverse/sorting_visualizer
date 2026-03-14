#include "../sorting.h"

// ===================== TIM SORT =====================
static const int TIM_RUN = 32;

// Insertion sort on a sub-array [left..right]
static void timInsertionSort(int* arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int j = i;
        while (j > left) {
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

// In-place merge [left..mid] and [mid+1..right] using swap-based shifting
static void timMerge(int* arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;

    // Already sorted
    if (sortLessEq(arr[mid], arr[j])) {
        addStep(STEP_COMPARE, mid, j);
        return;
    }

    while (i <= mid && j <= right) {
        addStep(STEP_COMPARE, i, j);

        if (sortLessEq(arr[i], arr[j])) {
            i++;
        } else {
            // Shift arr[j] into position i via adjacent swaps
            int index = j;
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

static void doTimSort(int* arr, int n) {
    // Sort individual runs with insertion sort
    for (int i = 0; i < n; i += TIM_RUN) {
        int right = i + TIM_RUN - 1;
        if (right >= n) right = n - 1;
        timInsertionSort(arr, i, right);
    }

    // Merge runs, doubling size each iteration
    for (int size = TIM_RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = left + 2 * size - 1;
            if (mid >= n) continue;
            if (right >= n) right = n - 1;
            timMerge(arr, left, mid, right);
        }
    }
}
