typedef struct station
{
    int num, fuel;
} Sta;

Sta heap[10005];
int ans[100005], len_heap = 0;

void swap(Sta *a, Sta *b)//交换代码
{
    Sta c;
    c = *a;
    *a = *b;
    *b = c;
}
void ins_heap(int num, int fuel)
{
    int i;
    heap[len_heap].num = num;
    heap[len_heap].fuel = fuel;
    len_heap++;
    i = len_heap - 1;
    while (i > 0)
    {
        if (heap[i].fuel > heap[(i - 1) / 2].fuel) 
        {
            swap(&heap[i], &heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        else
        {
            break;
        }
    }
}

void adjust_heap(int loc)
{
    int i = loc, j = loc * 2 + 1;//辅助变量j
    while (i <= len_heap - 1)
    {
        if (i * 2 + 1  <= len_heap - 1)
        {
            if (i * 2 + 2 <= len_heap - 1 && heap[i * 2 + 1].fuel <= heap[i * 2 + 2].fuel)
            {
                j = i * 2 + 2;
            }
            else
            {
                j = i * 2 + 1;
            }
            if (heap[i].fuel < heap[j].fuel)
            {
                swap(&heap[i], &heap[j]);
                i = j;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void del_heap(int loc)
{
    heap[loc] = heap[len_heap - 1];
    len_heap--;
    adjust_heap(loc);
}



int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize){
    int i, cnt = startFuel, loc = 0;
    memset(ans, -1, sizeof(ans));//置为-1
    len_heap = 0;
    ans[0] = 0;
    for (i = 0; i <= stationsSize - 1; i++)
    {
        if (cnt >= stations[i][0] - loc)
        {
            ans[i + 1] = ans[i];//车站编号从1开始，车站下标从0开始
            cnt -= (stations[i][0] - loc);
        }
        else
        {
            ans[i + 1] = ans[i];
            while (len_heap > 0)
            {
                cnt = cnt + heap[0].fuel;
                ans[i + 1]++;
                del_heap(0);//删除
                if (cnt >= stations[i][0] - loc)
                {
                   break;
                } 
            }
            if (cnt >= stations[i][0] - loc)
            {
                cnt -= (stations[i][0] - loc);
            }
            else
            {
                ans[i + 1] = -1;
                break;
            }
        }
        ins_heap(i + 1, stations[i][1]);//可选择加油的数量增加
        loc = stations[i][0];//位置提升
    }
    ans[i + 1] = ans[i];
    if (cnt < target - loc)
    {
        while (len_heap > 0)
        { 
            cnt = cnt + heap[0].fuel;
            ans[i + 1]++;
            del_heap(0);//删除
            if (cnt >= (target - loc))
            {
                break;
            } 
        }
        if (cnt >= (target - loc))
        {
            cnt -= (target - loc); 
        }
        else
        {
            ans[i + 1] = -1;
        }
    }
    return ans[stationsSize + 1];
}
