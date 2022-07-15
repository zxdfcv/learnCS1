typedef struct node{//又是字典树模板题
    int flag;
    char ch;
    struct node* alpha[26]; 
} MagicDictionary, *Trie;


MagicDictionary* magicDictionaryCreate() {
    int i;
    Trie root = (Trie)malloc(sizeof(MagicDictionary));
    for (i = 0; i <= 25; i++)
    {
        root->alpha[i] = NULL;
    }
    root->ch = '\0';
    root->flag = 0;
    return root;
}

void magicDictionaryBuildDict(MagicDictionary* obj, char ** dictionary, int dictionarySize) {
  int i, j, k, l, cnt;
  Trie p = NULL, q = NULL, r = NULL;
  for (i = 0; i <= dictionarySize - 1; i++)
  {
      p = obj;
      for (j = 0; dictionary[i][j] != '\0'; j++)
      {
        cnt = dictionary[i][j] - 'a';
        if (p->alpha[cnt] == NULL)
        {
            p->alpha[cnt] = (Trie)malloc(sizeof(MagicDictionary));
            for (l = 0; l <= 25; l++)
            {
                p->alpha[cnt]->alpha[l] = NULL;
            }
            p->alpha[cnt]->ch = dictionary[i][j];
            p->alpha[cnt]->flag = 0;
        }//特判
        p = p->alpha[cnt];
        if (dictionary[i][j + 1] == '\0')
        {
                p->flag = 1;
                break;
        }
      }
  }
}

bool magicDictionarySearch(MagicDictionary* obj, char * searchWord) {
    int i, j, k, cnt, ans = 0;
    Trie p = obj, q = NULL;
    char buff[105], tmp;

    if (obj == NULL)
    {
        return false;
    }
    strcpy(buff, searchWord);
    for (i = 0; searchWord[i] != '\0'; i++)
    {
        tmp = buff[i];
        for (j = 0; j <= 25; j++)
        {
            if (tmp == 'a' + j)
            {
                continue;
            }
            buff[i] = 'a' + j;
            p = obj;
            for (k = 0; buff[k] != '\0'; k++)
            {
                cnt = buff[k] - 'a';    
                if (p->alpha[cnt] != NULL)
                {
                    p = p->alpha[cnt];
                    //继续搜索
                }
                else
                {
                    break;
                }
                if (buff[k + 1] == '\0')
                {
                    if (p->flag == 1)
                    {
                        return true;//有标记
                    }
                }
            }
        }
        buff[i] = tmp;
    }
    return false;
}

void magicDictionaryFree(MagicDictionary* obj) {

    int i;
    if (obj != NULL)
    {
        for (i = 0; i <= 25; i++)
        {
            magicDictionaryFree(obj->alpha[i]);
        }
        free(obj);
    }
}//不够巧妙的字典树

/**
 * Your MagicDictionary struct will be instantiated and called as such:
 * MagicDictionary* obj = magicDictionaryCreate();
 * magicDictionaryBuildDict(obj, dictionary, dictionarySize);
 
 * bool param_2 = magicDictionarySearch(obj, searchWord);
 
 * magicDictionaryFree(obj);
*/
//学习面向对象
