int row[55], column[55], cntr, cntc, ans;
int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize){
    memset(row, 0, sizeof(row));
    memset(column, 0, sizeof(column));
    cntr = cntc = ans = 0;
    int i, j;
    for (i = 0; i <= indicesSize - 1; i++)
    {
        if (row[indices[i][0]] == 1)
        {
            row[indices[i][0]] = 0;
            ans = ans - (n - cntc) + cntc;
            cntr--;
        }
        else
        {
            row[indices[i][0]] = 1;
            ans = ans + (n - cntc) - cntc;
            cntr++;
        }

        if (column[indices[i][1]] == 1)
        {
            column[indices[i][1]] = 0;
            ans = ans - (m - cntr) + cntr;
            cntc--;
        }
        else
        {
            column[indices[i][1]] = 1;
            ans = ans + (m - cntr) - cntr;
            cntc++;
        }
    }
    return ans;//��ѽ��
}//ʵ���Ͼ����������б任����Ҫ
