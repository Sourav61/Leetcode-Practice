class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;
        for(auto c : nums)
            currSum = max(c, currSum + c),
            maxSum = max(maxSum, currSum);
        return maxSum;
    }
};