void moveZeroes(int* nums, int numsSize) {
    int index = 0;

    // Move all non-zero elements to the front
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[index++] = nums[i];
        }
    }

    // Fill the remaining positions with zeros
    while (index < numsSize) {
        nums[index++] = 0;
    }
}
