class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> temp;
        set<int> v;
        for(int i=0;i<n;i++){
            if(nums[i] == key){
                temp.push_back(i);
            }
        }
        
        for(auto x : temp){
            for(int i=0;i<n;i++){
                if(abs(i-x) <= k)
                    v.insert(i);
            }
        }
        vector<int> res;

        for(auto x : v){
            res.push_back(x);
        }cout<<endl;

        return res;
    }
};