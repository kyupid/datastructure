//
// Created by Yeonwoo Kim on 2023/12/09.
//
#include <stdio.h>
#include <string.h>
#include <malloc/_malloc.h>

typedef struct NODE {
    char szData[64];
    struct NODE *next;
} NODE;

// 더미 헤드
NODE g_head = {0}; // 많은 경우 동적할당을 함

/*연결 리스트 전체 데이터 출력*/
void PrintList(void) {
    NODE *pCurrent = g_head.next;
    while (pCurrent != NULL) {
        printf("[%p] %s\n", pCurrent, pCurrent->szData);
        pCurrent = pCurrent->next;
    }
    putchar('\n');
}

int IsEmpty() {
    if (g_head.next == NULL) {
        return 1;
    }
    return 0;
}

int InsertAtHead(char *pszData) {
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

int InsertAtTail(char *pszData) {
    //마지막 노드를 찾는다
    NODE *pTmp = &g_head;
    while (pTmp->next != 0) {
        pTmp = pTmp->next;
    }

    NODE *pNode = (NODE *) malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strcpy(pNode->szData, pszData);

    pTmp->next = pNode;
    return 1;
}

void ReleaseList(void) {
    printf("\nReleaseList()\n");
    NODE *pTmp = g_head.next;
    while (pTmp != NULL) {
        NODE *pDelete = pTmp;
        pTmp = pTmp->next;

        printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
        free(pDelete);
    }

    g_head.next = 0;
}

NODE *FindData(char *pszData) {
    NODE *pCurr = g_head.next;
    NODE *pPrev = &g_head;
    while (pCurr != NULL) {
        if (strcmp(pCurr->szData, pszData) == 0) {
            return pPrev;
        }
        pCurr = pCurr->next;
        pPrev = pPrev->next;
    }
    return 0;
}

int DeleteDate(char *pszData) {
    NODE *pPrev = FindData(pszData);
    while (pPrev != 0) {
        NODE *pDelete = pPrev->next;
        pPrev->next = pDelete->next;

        printf("DeleteData() %s\n", pDelete->szData);
        free(pDelete);
        return 1;
    }
    return 0;
}

void Enqueue(char *pszData) {
    InsertAtHead(pszData);
}

int Dequeue(NODE *dequeNode) {
    if (IsEmpty()) {
        return 0;
    }
    //마지막 노드를 찾는다
    NODE *pPrev = &g_head;
    NODE *pCurr = g_head.next;
    while (pCurr->next != 0) {
        pPrev = pCurr;
        pCurr = pCurr->next;
    }
    printf("pPrev: %s, pCurr: %s\n", pPrev->szData, pCurr->szData);

    g_head.next = pPrev;
    memcpy(dequeNode, pCurr, sizeof(NODE));
    printf("Dequeue(): %s\n", pCurr->szData);
    free(pCurr);
    pPrev->next = 0;

    return 1;
}

int main() {
    Enqueue("TEEST01");
    Enqueue("TEEST02");
    Enqueue("TEEST03");
    PrintList();

    NODE node = {0};
    Dequeue(&node);

    PrintList();

    ReleaseList();
    return 0;
}