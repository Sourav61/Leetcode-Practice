class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {

        vector<string> ans;

        int n = words.size();

        string f = words[0];
        ans.push_back(f);
        sort(f.begin(),f.end());

        for(int i=1;i<n;i++){
            string s = words[i];
            sort(s.begin(),s.end());
            if(f == s)
                continue;
            else{
                ans.push_back(words[i]);
                f = s;           
            } 
        }

        return ans;
    }
};