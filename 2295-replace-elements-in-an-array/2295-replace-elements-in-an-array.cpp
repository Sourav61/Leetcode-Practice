class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int,int> m1,m2;

        for(int i=0;i<nums.size();i++){
            m1[nums[i]] = i+1;
            m2[i+1] = nums[i];
        }

        for(auto x: operations){
            int value = x[0], new_value = x[1];
            int index = m1[value];

            m2[index] = new_value;

            m1.erase(value);
            m1[new_value] = index;
        }

        vector<int> ans;

        for(auto x:m2){
            ans.push_back(x.second);
        }

        return ans;
    }
};