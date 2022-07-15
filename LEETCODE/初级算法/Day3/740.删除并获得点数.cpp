


class Solution {
private: 
    int robbery(vector<int> &nums)
    {
        int nums_size = nums.size();//max_val + 1;
        int a = nums[0], b = max(nums[1], a);//max_val + 1防止溢出
        for (int i = 2; i <= nums_size - 1; i++)//c++11高级写法
        {
            int tmp = b;
            b = max(a + nums[i], b);
            a = tmp;
        }
        return b;
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_val;
        for (auto val : nums)//c++11高级写法
        {
            max_val = max(val, max_val);
        }
        vector<int> ans(max_val + 1);//定义单个向量大小用括号
        for (auto val : nums)
        {
            ans[val] += val;
        }
        return robbery(ans);
    }//Java风格C++
};
