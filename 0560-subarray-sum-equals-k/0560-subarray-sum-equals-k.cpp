class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int CumSum = 0;
        int result = 0;
        for(int i = 0; i<n;i++){
            CumSum += nums[i];
            if(mp.find(CumSum - k)!= mp.end()){
                result += mp[CumSum - k];
            }
            mp[CumSum]++;
        }
        return result;
    }
};