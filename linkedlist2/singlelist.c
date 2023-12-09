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

int FindData(char *pszData) {
    NODE *pTmp = g_pHead;
    while (pTmp != NULL) {
        if (strcmp(pTmp->szData, pszData) == 0) {
            return 1;
        }
        pTmp = pTmp->next;
    }
    return 0;
}

int main() {
    // List 테스를 위한 코드
    InsertNewNode("TEST01");
    PrintList();

    // START - strcmp 함수 테스트
    NODE *temp2 = (NODE *) malloc(sizeof(NODE)); // Create the temp2 node
    strcpy(temp2->szData, "hello"); // Insert the data into temp2
    int test = strcmp(temp2->szData, g_pHead->szData);
    if (test == 0) {
        printf("일치\n");
    } else {
        printf("불일치 %d\n", test);
    }
    // END - strcmp 함수테스트

    InsertNewNode("TEST02");
    PrintList();

    InsertNewNode("TEST03");
    PrintList();

    if (FindData("TEST01") == 1) {
        printf("FindData(): TEST01 found \n");
    }
    if (FindData("TEST02") == 1) {
        printf("FindData(): TEST02 found \n");
    }
    if (FindData("TEST03") == 1) {
        printf("FindData(): TEST03 found \n");
    }
    ReleaseList();
    free(temp2); // Make sure to free the dynamically allocated node
    return 0;
}