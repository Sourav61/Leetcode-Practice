class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> num(nums.size()/2 , 0);
        
        for(int i=0;i<(nums.size())/2; i++){
            if(i%2==0){
                num[i] = min(nums[2 * i], nums[(2 * i) + 1]);
            }else{
                num[i] = max(nums[2 * i], nums[(2 * i) + 1]);
            }
        }
        
        return minMaxGame(num);
    }
};