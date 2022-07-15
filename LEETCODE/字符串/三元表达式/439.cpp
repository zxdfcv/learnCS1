//char op[1005];
char num[1005];
int len_op = 0, len_num = 0;
char * parseTernary(char * expression){
    int i, j, len = strlen(expression), cnt = 0;
    char *ch;
    len_op = 0;
    len_num = 0;
    for (i = len - 1; i >= 0; i--)//从右向左运算是核心，循其道 
    {
        if (expression[i] == '?')
        {
            if (expression[i - 1] == 'T')
            {
                num[len_num - 2] = num[len_num - 1];
                len_num--;
                num[len_num] = '\0';
            }
            else if (expression[i - 1] == 'F')
            {
                len_num--;
                num[len_num] = '\0';
            }
            i--;
        }
        else if (expression[i] == 'T' || expression[i] == 'F' || isdigit(expression[i]))
        {
            num[len_num] = expression[i];
            len_num++;
        }
    }
    ch = &num[0];
    return ch;
}//先练简单的

