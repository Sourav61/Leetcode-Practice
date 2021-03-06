class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt[101] = {};
        int res = 0;
        for (auto x : nums)
            cnt[x]++;
        for (int i = k + 1; i < 101; ++i)
            res += cnt[i] * cnt[i - k];
        return res;
    }
};