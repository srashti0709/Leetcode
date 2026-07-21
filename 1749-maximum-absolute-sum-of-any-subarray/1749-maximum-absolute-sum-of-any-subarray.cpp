class Solution {
public:
    int kadanesMax(vector<int>& nums, int n){
        int sum = nums[0];
        int maxSum = nums[0];
        for(int i =1;i<n;i++){
            sum = max(sum+nums[i],nums[i]);
            maxSum = max(sum,maxSum);
        }
        return maxSum;
    }
    int kadanesMin(vector<int>& nums, int n){
        int sum = nums[0];
        int minSum = nums[0];
        for(int i =1;i<n;i++){
            sum = min(sum+nums[i],nums[i]);
            minSum = min(sum,minSum);
        }
        return minSum;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = kadanesMax(nums,n);
        int minSum = kadanesMin(nums,n);
        int abMax = abs(maxSum);
        int abMin = abs(minSum);
        return max(abMax,abMin);
    }
};