/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node
{
    int num;
    struct node *next;
} *LNode, LinkList;

typedef struct head
{
    int total;
    struct node *next;
} Head;
int num[50], ans[10005], len_ans = 0, len_num = 0, len_op = 0;
char op[50];

Head dp[50][50];
//struct ListNode �������ֳɵ�����ڵ� 
LNode dfs(int l, int r)//���仯����//Ӧ�÷���ָ��
{
    int i, j, x;
    LNode p = NULL, q = NULL, s = NULL, t = NULL, ptr = NULL;
    if (dp[l][r].total > 0)//���仯����
    {
        return dp[l][r].next;
    }
    if (l == r)//�߽�����
    {
        dp[l][r].total = 1;
        dp[l][r].next = (LNode)malloc(sizeof(LinkList));
        dp[l][r].next->num = num[l];
        dp[l][r].next->next = NULL;
        return dp[l][r].next;
    }
    ptr = dp[l][r].next;
    for (i = l; i <= r - 1; i++)
    {
        if (dp[l][i].total > 0)
        {
            p = dp[l][i].next;
        }
        else
        {
            p = dfs(l, i);
        }
        if (dp[i + 1][r].total > 0)//�Ƿ��Ѿ�������
        {
            q = dp[i + 1][r].next;
        }
        else
        {
            q = dfs(i + 1, r);
        }
        if (op[i] == '+')
        {
            while (p != NULL)
            {
                s = q;
                while (s != NULL)
                {
                    t = malloc(sizeof(LinkList));
                    t->next = NULL;
                    t->num = p->num + s->num;
                    dp[l][r].total++;
                    if (ptr == NULL)
                    {
                        dp[l][r].next = t;//��Ϊ��һ��Ԫ��
                        ptr = dp[l][r].next;//����
                    }
                    else
                    {
                        ptr->next = t;
                        ptr = ptr->next;
                    }
                    s = s->next;
                }
                p = p->next;
            }
        }
        else if (op[i] == '-')
        {
            while (p != NULL)
            {
                s = q;
                while (s != NULL)
                {
                    t = malloc(sizeof(LinkList));
                    t->next = NULL;
                    t->num = p->num - s->num;
                    dp[l][r].total++;
                    if (ptr == NULL)
                    {
                        dp[l][r].next = t;
                        ptr = dp[l][r].next;//����
                    }
                    else
                    {
                        ptr->next = t;
                        ptr = ptr->next;
                    }
                    s = s->next;
                }
                p = p->next;
            }
        }
        else if (op[i] == '*')
        {
            while (p != NULL)
            {
                s = q;
                while (s != NULL)
                {
                    t = malloc(sizeof(LinkList));
                    t->next = NULL;
                    t->num = p->num * s->num;
                    dp[l][r].total++;
                    if (ptr == NULL)
                    {
                        dp[l][r].next = t;
                        ptr = dp[l][r].next;//����
                        
                    }
                    else
                    {
                        ptr->next = t;
                        ptr = ptr->next;
                    }
                    s = s->next;
                }
                p = p->next;
            }
        }
        else
        {
            dp[l][r].next = NULL;//����
        }
    }
    return dp[l][r].next;
}
int* diffWaysToCompute(char *expression, int *returnSize){
    int i, j, cnt = 0;
    len_ans = len_num = len_op = 0;
    LNode p = NULL;
    for (i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            cnt = 0;
            for (j = i; expression[j] != '\0' && expression[j] >= '0' && expression[j] <= '9'; j++)
            {
                cnt = cnt * 10 + expression[j] - '0';
            }
            num[len_num] = cnt;
            len_num++;
            i = j - 1;
        }
        else if (expression[i] == '+')
        {
            op[len_op++] = '+';
        }
        else if (expression[i] == '-')
        {
            op[len_op++] = '-';
        }
        else if (expression[i] == '*')//����ֱ����ջ
        {
            op[len_op++] = '*';
        }
    }
    //������źͲ�����
    memset(dp, 0, sizeof(dp));//��ʼ��
    dfs(0, len_num - 1);//len_num ��len_op��1
    p = dp[0][len_num - 1].next;//���𰸷�������
    while (p != NULL)
    {
        ans[len_ans] = p->num;
        len_ans++;
        p = p->next;
    }//len_ans == total
    *returnSize = len_ans;
    return ans;
}
