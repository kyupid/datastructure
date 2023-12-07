#include <stdio.h>

typedef struct NODE {
    //관리될 데이터
    int nData;

    //데이터 관리를 위한 포인터
    struct NODE* next;
} NODE;

int main() {
    NODE list[5] = { 0 };

    list[0].next = &list[1];
    list[1].next = &list[2];
    list[2].next = &list[3];
    list[3].next = &list[4];
    list[4].next = NULL; // 0이라고 써도됨

    return 0;
}


