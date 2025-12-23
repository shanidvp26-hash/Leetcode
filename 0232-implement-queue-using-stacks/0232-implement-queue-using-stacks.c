
#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    Stack inStack;
    Stack outStack;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->inStack.top = -1;
    q->outStack.top = -1;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->inStack.data[++obj->inStack.top] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->outStack.top == -1) {
        while (obj->inStack.top != -1) {
            obj->outStack.data[++obj->outStack.top] =
                obj->inStack.data[obj->inStack.top--];
        }
    }
    return obj->outStack.data[obj->outStack.top--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->outStack.top == -1) {
        while (obj->inStack.top != -1) {
            obj->outStack.data[++obj->outStack.top] =
                obj->inStack.data[obj->inStack.top--];
        }
    }
    return obj->outStack.data[obj->outStack.top];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->inStack.top == -1 && obj->outStack.top == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
