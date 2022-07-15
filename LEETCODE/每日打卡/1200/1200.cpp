/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int *ans[100005], len_ans = 0;
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}//先排序


int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
//基本范式
    int i, j, cnt = 2147483647;
    len_ans = 0;
    qsort(arr, arrSize , sizeof(int), cmp);
    for (i = 0; i <= arrSize - 2; i++)
    {
        if (arr[i + 1] - arr[i] < cnt)
        {
            for (j = 0; j <= len_ans - 1; j++)
            {
                free(ans[j]);
            }
            len_ans = 0;
            cnt = arr[i + 1] - arr[i];
            ans[len_ans] = (int*)malloc(sizeof(int) * 2);
            ans[len_ans][0] = arr[i];
            ans[len_ans][1] = arr[i + 1];
            //(*returnColumnSizes)[len_ans] = 2;
            len_ans++;
        }
        else if (arr[i + 1] - arr[i] == cnt)
        {
            cnt = arr[i + 1] - arr[i];
            ans[len_ans] = (int*)malloc(sizeof(int) * 2);
            ans[len_ans][0] = arr[i];
            ans[len_ans][1] = arr[i + 1];
            //(*returnColumnSizes)[len_ans] = 2;
            len_ans++;
        }
    }
    *returnSize = len_ans; 
    *returnColumnSizes = (int *)malloc(sizeof(int) * len_ans);
    for (int i = 0; i <= len_ans - 1; i++) 
    {
        (*returnColumnSizes)[i] = 2;
    }
    return ans;
}
