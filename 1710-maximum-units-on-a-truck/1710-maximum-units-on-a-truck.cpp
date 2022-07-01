class Solution {
public:
    static bool sortSec(const vector<int>& v1, const vector<int> &v2){
        return v1[1]>v2[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),sortSec);
        int sum = 0;

        for(vector<int> v : boxTypes){
            if(truckSize >= v[0]){
                sum += v[0] * v[1];
                truckSize -= v[0];
            }else if(truckSize <= v[0] && truckSize > 0){
                sum += truckSize * v[1];
                truckSize = 0;
            }
        }

        return sum;
    }
};