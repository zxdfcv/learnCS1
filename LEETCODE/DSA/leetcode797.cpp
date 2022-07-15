#include<stdio.h>
#include<stdlib.h>//指针很复杂 

 
int cnt[15] = {0};//数据规模
int **ans; 
 
void dfs(int len, int n, int* returnSize, int* graphColSize, int** returnColumnSizes, int** graph)
{
	if (cnt[len - 1] == n)//graphSize - 1
	{
		ans[*returnSize] = malloc(sizeof(int) * len);
		for (int i = 0; i <= len - 1; i++)
		{
			ans[*returnSize][i] = cnt[i];//* []作用相同 
		}
		(*returnColumnSizes)[(*returnSize)++] = len;
		return;	
	}
	else
	{
		for (int i = 0; i <= graphColSize[cnt[len - 1]] - 1; i++)
		{
			cnt[len] = graph[cnt[len - 1]][i];
			dfs(len + 1, n, returnSize, graphColSize, returnColumnSizes, graph);
		}
		//回退 
	}	
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes)//遍历函数 
{
	*returnSize = 0;//初始化
    *returnColumnSizes = malloc(sizeof(int) * 16384);//确定数据范围
	ans = malloc(sizeof(int*) * 16384);
	dfs(1, graphSize - 1, returnSize, graphColSize, returnColumnSizes, graph);
	return ans; 
}

int main()
{
	int **graph = (int**)malloc(sizeof(int*) * 4);
	int graphSize = 4; 
	int graphColSize[4] = {2, 1, 1, 0};
	int* returnSize;
	int** returnColumnSizes;
	graph[0] = (int*)malloc(sizeof(int) * 2);
	graph[0][0] = 1, graph[0][1] = 2;
	graph[1] = (int*)malloc(sizeof(int) * 2);
	graph[2] = (int*)malloc(sizeof(int) * 2);
	graph[1][0] = graph[2][0] = 3;
	allPathsSourceTarget(graph, graphSize, graphColSize, returnSize, returnColumnSizes);
	return 0;
} 
