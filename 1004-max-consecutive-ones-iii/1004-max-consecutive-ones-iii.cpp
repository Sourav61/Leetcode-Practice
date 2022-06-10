class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCnt = 0, ans = INT_MIN, i=0;
        int n = nums.size();
        for(int j=0;j<n;j++){
            if(nums[j] == 0){
                zeroCnt++;
            }

            while(zeroCnt > k){
                if(nums[i] == 0){
                    zeroCnt--;
                }
                i++;
            }

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};