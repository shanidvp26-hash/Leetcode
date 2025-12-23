
typedef struct {
    int *q1;
    int *q2;
    int size1;
    int size2;
    int capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack *obj = (MyStack*)malloc(sizeof(MyStack));
    obj->capacity = 200;
    obj->q1 = (int*)malloc(sizeof(int) * obj->capacity);
    obj->q2 = (int*)malloc(sizeof(int) * obj->capacity);
    obj->size1 = 0;
    obj->size2 = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    obj->q2[obj->size2++] = x;

    for (int i = 0; i < obj->size1; i++) {
        obj->q2[obj->size2++] = obj->q1[i];
    }

    int *temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;

    obj->size1 = obj->size2;
    obj->size2 = 0;
}

int myStackPop(MyStack* obj) {
    int top = obj->q1[0];
    for (int i = 1; i < obj->size1; i++) {
        obj->q1[i - 1] = obj->q1[i];
    }
    obj->size1--;
    return top;
}

int myStackTop(MyStack* obj) {
    return obj->q1[0];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size1 == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}
