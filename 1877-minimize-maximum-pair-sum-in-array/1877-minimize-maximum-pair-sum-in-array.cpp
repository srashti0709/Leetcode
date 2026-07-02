class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int elem = 0;
        while(l<r){
            int sum = nums[l] + nums[r];
            l++;
            r--;
            elem = max(elem, sum);
        }

        
        return elem;
    }
};