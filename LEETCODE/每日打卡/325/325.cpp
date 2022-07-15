class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {//向量模板类
    int i, n = nums.size();
    long long ans = 0, cnt = 0, t;
    unordered_map<long long, long long> prefix_map;//不会爆炸
    prefix_map[0] = -1;//先值条件很重要
    for (i = 0; i <= n - 1; i++)//下标从零开始
    {
        cnt += nums[i];
        if (prefix_map.count(cnt - k) != 0)//判断是否满足条件
        {
            ans = max(ans, i - prefix_map[cnt - k]);//减去cnt
        }
        if (prefix_map.count(cnt) == 0)//还没有映射
        {
            prefix_map[cnt] = i;
        }
    }
    return ans;
    }
};
