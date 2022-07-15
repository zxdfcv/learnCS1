#include"uthash.h"
#include<stdio.h>

//��ϣ��ͷ�ļ��÷� O(1)���Ӷ� 
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;//��ϣ��� 
} HashItem;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lenLongestFibSubseq(int* arr, int arrSize){
    HashItem *indices = NULL, *pEntry = NULL;
    for (int i = 0; i < arrSize; i++) {
        pEntry = (HashItem *)malloc(sizeof(HashItem));
        pEntry->key = arr[i];
        pEntry->val = i;
        HASH_ADD_INT(indices, key, pEntry);//���Ԫ�� 
    }
    int **dp = (int **)malloc(sizeof(int *) * arrSize);
    int ans = 0;
    for (int i = 0; i < arrSize; i++) {
        dp[i] = (int *)malloc(sizeof(int) * arrSize);
        memset(dp[i], 0, sizeof(int) * arrSize);
    }
    for (int i = 0; i < arrSize; i++) {
        for (int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; j--) {//����ѭ��,ʱ�临�Ӷ�O(n * n) 
            int k = -1;
            int target = arr[i] - arr[j];
            pEntry = NULL;
            HASH_FIND_INT(indices, &target, pEntry);//����Ԫ�� val����� key����Ŷ�Ӧ��ֵ 
            if (pEntry) {
                k = pEntry->val;
            }
            if (k >= 0) {
                dp[j][i] = MAX(dp[k][j] + 1, 3);
            }
            ans = MAX(ans, dp[j][i]);
        }
    }
    for (int i = 0; i < arrSize; i++) {
        free(dp[i]);
    }
    free(dp);
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, indices, curr, tmp) {
        HASH_DEL(indices, curr);//ɾ��Ԫ��  
        free(curr);         
    }
    return ans;
}


