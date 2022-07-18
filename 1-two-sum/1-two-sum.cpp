class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> v;

        for(int i=0;i<nums.size();i++){
            int toFind = target - nums[i];

            if(mpp.find(toFind) != mpp.end()){
                v.push_back(mpp[toFind]);
                v.push_back(i);
                return v;
            }

            mpp[nums[i]] = i;        
        }

        return v;
    }
};