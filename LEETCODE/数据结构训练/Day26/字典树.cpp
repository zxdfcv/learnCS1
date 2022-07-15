typedef struct trie
{
    char ch;
    int flag;
    struct trie* alpha[26];
} *Trie, TrieNode;//字典树
Trie root = NULL;
int len = 0, cnt = 0;
char ans[100005];
char cntt[100005];


void Search_Trie(Trie p)
{
    int i;
    for (i = 0; i <= 25; i++)
    {
        if (p->alpha[i] != NULL && p->alpha[i]->flag == 1)
        {   
            cntt[cnt++] = p->alpha[i]->ch;
            Search_Trie(p->alpha[i]);
            cnt--;
        }
        else if(p->alpha[i] == NULL)
        {
            if (len < cnt)
            {
                strcpy(ans, cntt);//复制
                len = cnt;
            } 
        }
        else if (p->alpha[i]->flag == 0)
        {
            if (len < cnt)
            {
                strcpy(ans, cntt);//复制
                len = cnt;
            }
        }
    }
}
char * longestWord(char ** words, int wordsSize){
//字典树实现
    len = cnt = 0;//初始化
    root = NULL;
    int i, j, k, l, ind, len_word;
    Trie p = NULL, q = NULL;
    root = (Trie)malloc(sizeof(TrieNode));
    for (i = 0; i <= 25; i++)
    {
        root->alpha[i] = NULL;
    }
    for (i = 0; i <= wordsSize - 1; i++)
    {   
        p = root;
        for (j = 0; words[i][j] != '\0'; j++)
        {
            ind = words[i][j] - 'a';
            if (p->alpha[ind] == NULL)
            {
                p->alpha[ind] = (Trie)malloc(sizeof(TrieNode));
                for (l = 0; l <= 25; l++)
                {
                    p->alpha[ind]->alpha[l] = NULL;
                    p->alpha[ind]->ch = words[i][j];
                    p->alpha[ind]->flag = 0;
                }
            }
            p = p->alpha[ind];//跳转
            if (words[i][j + 1] == '\0')
            {
                p->flag = 1;
            }
        }
    }//构建字典树
    Search_Trie(root);
    ans[len] = '\0';
    return ans;
}
