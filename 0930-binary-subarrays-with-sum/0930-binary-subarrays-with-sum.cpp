class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int result = 0;
        int CurrSum = 0;
        for(int i=0;i<n;i++){
            CurrSum += nums[i];
            int rem = CurrSum - goal;
            if(mp.find(rem) != mp.end()){
                result += mp[rem];
            }
            mp[CurrSum]++;
        }
        return result;
    }
};