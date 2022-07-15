int arr[105], len_arr = 0;//广义Next_permutation

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int search(int buff[], int len, int tmp)
{
    int i, cnt = -1;//记录下脚标
    for (i = 0;  i <= len - 1; i++)//对于顺序表，函数可简化
    {
        if (buff[i] > tmp && cnt == -1)
        {
            cnt = i;
        }
        else if (buff[i] > tmp && buff[i] <= buff[cnt])
        {
            cnt = i;
        }
    }
    return cnt;
}
int Next_permutation(int buff[], int len)
{
    int i, j, tmp, flag;
    for (i = len - 1; i >= 1; i--)
    {
        if (buff[i - 1] < buff[i])
        {
            break;
        }
    }
    if (i == 0)
    {
        return -1;
    }
    tmp = buff[i - 1];
    flag = search(buff + i, len - i, tmp) + i;//找大于tmp中最小者
    if (flag == -1)
    {
        return -1;//异常
    }
    //排序
    swap(&buff[i - 1], &buff[flag]);
    for (j = i; j <= len - 1 - j + i; j++)
    {
        swap(&buff[j], &buff[len - 1 - j + i]);//由单调递减改为递增
    }
    return 1;//返回值-1/1
}
int nextGreaterElement(int n){
    int i, x = n;
    long long ans = 0;
    len_arr = 0;//初始化
    do//取数
    {
        arr[len_arr] = x % 10;
        len_arr++;
        x = x / 10;
    }
    while (x > 0);
    for (i = 0; i <= len_arr - 1 - i; i++)//颠倒
    {
        swap(&arr[i], &arr[len_arr - 1 - i]);
    }
    if (Next_permutation(arr, len_arr) == -1)
    {
        return -1;
    }
    else 
    {
        for (i = 0; i <= len_arr - 1; i++)
        {
            ans = ans * 10 + arr[i];
        }
        if (ans <= 2147483647)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
}
//实质上是next_permutation
