#include "../sorting.h"

// ===================== TREE SORT =====================
// BST-based sort: insert all elements into a BST, then in-order traverse
// to write back sorted values using swap-based placement for visualization.

struct BSTNode {
    int value;
    int originalIndex; // track where this value came from
    BSTNode* left;
    BSTNode* right;
};

static BSTNode nodePool[MAX_ARRAY_SIZE];
static int nodePoolCount;

static BSTNode* newNode(int value, int index) {
    BSTNode* n = &nodePool[nodePoolCount++];
    n->value = value;
    n->originalIndex = index;
    n->left = 0;
    n->right = 0;
    return n;
}

static BSTNode* bstInsert(BSTNode* root, int value, int index) {
    if (!root) return newNode(value, index);
    addStep(STEP_COMPARE, index, root->originalIndex);
    if (sortLessEq(value, root->value)) {
        root->left = bstInsert(root->left, value, index);
    } else {
        root->right = bstInsert(root->right, value, index);
    }
    return root;
}

// Collect sorted values from BST via in-order traversal
static int sortedValues[MAX_ARRAY_SIZE];
static int sortedCount;

static void inOrderCollect(BSTNode* root) {
    if (!root) return;
    inOrderCollect(root->left);
    sortedValues[sortedCount++] = root->value;
    inOrderCollect(root->right);
}

static void doTreeSort(int* arr, int n) {
    // Build BST
    nodePoolCount = 0;
    BSTNode* root = 0;
    for (int i = 0; i < n; i++) {
        root = bstInsert(root, arr[i], i);
    }

    // Collect sorted values
    sortedCount = 0;
    inOrderCollect(root);

    // Place sorted values into array using swaps for visualization
    for (int i = 0; i < n; i++) {
        if (arr[i] != sortedValues[i]) {
            // Find where sortedValues[i] currently is in arr
            int j = i + 1;
            while (j < n && arr[j] != sortedValues[i]) {
                j++;
            }
            if (j < n) {
                addStep(STEP_SWAP, i, j);
                swapElements(arr, i, j);
            }
        }
        addStep(STEP_SORTED, i, -1);
    }
}
