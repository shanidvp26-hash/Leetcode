int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int stack[10000];
    int top = -1;
    int next[10000];

    for (int i = 0; i < nums2Size; i++) {
        next[i] = -1;
    }

    for (int i = 0; i < nums2Size; i++) {
        while (top >= 0 && nums2[stack[top]] < nums2[i]) {
            next[stack[top]] = nums2[i];
            top--;
        }
        stack[++top] = i;
    }

    int* ans = (int*)malloc(nums1Size * sizeof(int));

    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                ans[i] = next[j];
                break;
            }
        }
    }

    *returnSize = nums1Size;
    return ans;
}
