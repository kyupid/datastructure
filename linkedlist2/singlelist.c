//
// Created by Yeonwoo Kim on 2023/12/08.
//
#include <stdio.h>
#include <string.h>
#include <malloc/_malloc.h>

typedef struct NODE {
    char szData[64];
    struct NODE *next;
} NODE;

NODE *g_pHead = NULL;

/*연결 리스트 전체 데이터 출력*/
void PrintList(void) {
    NODE *pHead = g_pHead;
    while (pHead != NULL) {
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }
    putchar('\n');
}

int InsertNewNode(char *pszData) {
    NODE *pNode = (NODE *) malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strcpy(pNode->szData, pszData);

    if (g_pHead == NULL) {
        g_pHead = pNode;
    } else {
        pNode->next = g_pHead;
        g_pHead = pNode;
    }
    return 1;
}

void ReleaseList(void) {
    NODE *pTmp = g_pHead;
    while (pTmp != NULL) {
        NODE *pDelete = pTmp;
        pTmp = pTmp->next;

        printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
        free(pDelete);
    }
}

int main() {
    // List 테스를 위한 코드
    InsertNewNode("TEST01");
    PrintList();

    InsertNewNode("TEST02");
    PrintList();

    InsertNewNode("TEST03");
    PrintList();

    ReleaseList();
    return 0;
}