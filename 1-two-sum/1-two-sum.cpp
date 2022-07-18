class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int a,b;
        vector<int> v;
        vector<int> temp = nums;
        sort(nums.begin(),nums.end());
        while(i < j){
            if(nums[i] + nums[j] == target){
                a = nums[i];
                b = nums[j];
                break;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
            else{
                j--;
            }
        }
        
        for(int i=0;i<n;i++){
            if(temp[i] == a || temp[i] == b)
                v.push_back(i);
        }
        
        return v;
    }
};