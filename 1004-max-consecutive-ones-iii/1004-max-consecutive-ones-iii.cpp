class Solution {
public:
    int longestOnes(vector<int>& nums, int K) {
        int i = 0, j;
        for (j = 0; j < nums.size(); ++j) {
            if (nums[j] == 0) K--;
            if (K < 0 && nums[i++] == 0) K++;
        }
        return j - i;
    }
};