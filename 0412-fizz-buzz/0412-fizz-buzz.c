char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char** answer = (char**)malloc(n * sizeof(char*));

    for (int i = 1; i <= n; i++) {
        answer[i - 1] = (char*)malloc(12 * sizeof(char)); // enough for "FizzBuzz" or number

        if (i % 15 == 0) {
            strcpy(answer[i - 1], "FizzBuzz");
        } else if (i % 3 == 0) {
            strcpy(answer[i - 1], "Fizz");
        } else if (i % 5 == 0) {
            strcpy(answer[i - 1], "Buzz");
        } else {
            sprintf(answer[i - 1], "%d", i);
        }
    }
    return answer;
}
