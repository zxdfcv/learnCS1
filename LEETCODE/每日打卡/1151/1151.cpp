class Solution {
public:
    int minSwaps(vector<int>& data) {//C++ѧ�㷨//ͬʱ�������ݽṹ
        int total = 0, n = data.size(), i, total_1 = 0, cnt_1 = 0, ans = 2147483647;
        for (i = 0; i  <= n - 1; i++)
        {
            if (data[i] == 1)
            {
                total_1++;
            }
        }//1������
        for (i = 0; i <= total_1 - 1; i++)
        {
            if (data[i] == 1)
            {
                cnt_1++;
            }
        }
        ans = total_1 - cnt_1;
        for (i = 1; i <= n - total_1; i++)
        {
            cnt_1 = cnt_1 + (data[i + total_1 - 1] == 1 ? 1 : 0) - (data[i - 1] == 1 ? 1 : 0);
            ans = min(ans, total_1 - cnt_1);
        }
        return ans;
    }//��������
    
};
