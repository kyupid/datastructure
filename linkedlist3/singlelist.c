//
// Created by Yeonwoo Kim on 2023/12/09.
//
#include <stdio.h>
#include <string.h>
#include <malloc/_malloc.h>

typedef struct NODE {
    char szData[64];
    struct NODE* next;
} NODE;

// 더미 헤드
NODE g_head = {0}; // 많은 경우 동적할당을 함

int IsEmpty() {
    if (g_head.next == NULL) {
        return 1;
    }
    return 0;
}

int InsertAtHead(char* pszData) {
    NODE *pNode = (NODE *) malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strcpy(pNode->szData, pszData);

    if (IsEmpty()) {
        g_head.next = pNode;
    } else {
        pNode->next = g_head.next;
        g_head.next = pNode;
    }
    return 1;
}

int InsertAtTail(char* pszData) {
    //마지막 노드를 찾는다
    NODE *pTmp = &g_head;
    while (pTmp->next != 0) {
        pTmp = pTmp->next;
    }

    NODE *pNode = (NODE *) malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strcpy(pNode->szData, pszData);

    pTmp->next = pNode;
}

int main() {

}