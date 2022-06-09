class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int count = 0;
        int mini = INT_MAX;

        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(mini == INT_MAX){
                mini = nums[i];
                count++;
            }
            else{
                if(nums[i] - mini > k){
                    mini = nums[i];
                    count++;
                }
            }
        }

        return count;

    }
};