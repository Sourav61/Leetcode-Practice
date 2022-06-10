class Solution {
public:
    int maxPower(string s) {
        int ans=0, count=1;
        char a;
        for(int i=0;i<s.length();i++){
            // int count=1;
            // cout<<s[i]<<" "<<s[i+1];
            if(s[i] == s[i+1]){
                count++;
            }else{
                count=1;
            }
            // cout<<s[i]<<" "<<i<<" "<<count<<endl;
            ans = max(ans,count);
        }
        
        return ans;
    }
};