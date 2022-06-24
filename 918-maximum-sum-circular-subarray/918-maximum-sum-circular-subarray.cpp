class Solution {
public:
    int kadane(vector<int> &nums){
        int currSum = 0, maxSum = INT_MIN;
        for(auto x : nums){
            currSum = max(x, x+currSum);
            maxSum = max(maxSum, currSum);
            
            // cout<<maxSum<<" "<<currSum<<endl;
        }

        return maxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int wrapSum;
        int nonwrapSum;
        
        int n = nums.size();

        nonwrapSum = kadane(nums);
        if(nonwrapSum<0){
            return nonwrapSum;
        }

        int totalSum = 0;

        for(int i=0;i<n;i++){
            totalSum+=nums[i];
            nums[i] = -nums[i];
        }

        wrapSum = totalSum + kadane(nums);
        
        cout<<wrapSum<<" "<<nonwrapSum<<endl;

        return max(wrapSum, nonwrapSum);
    }
};