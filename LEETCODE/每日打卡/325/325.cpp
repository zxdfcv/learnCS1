class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {//����ģ����
    int i, n = nums.size();
    long long ans = 0, cnt = 0, t;
    unordered_map<long long, long long> prefix_map;//���ᱬը
    prefix_map[0] = -1;//��ֵ��������Ҫ
    for (i = 0; i <= n - 1; i++)//�±���㿪ʼ
    {
        cnt += nums[i];
        if (prefix_map.count(cnt - k) != 0)//�ж��Ƿ���������
        {
            ans = max(ans, i - prefix_map[cnt - k]);//��ȥcnt
        }
        if (prefix_map.count(cnt) == 0)//��û��ӳ��
        {
            prefix_map[cnt] = i;
        }
    }
    return ans;
    }
};
