class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int currentSum = 0;
        int result = 0;
        int count_zeros = 0;
        while(j<n){
            currentSum += nums[j];
            while(i < j && (nums[i] == 0 || currentSum > goal)){
                if(nums[i] == 0){
                    count_zeros++; 
                }
                else{
                    count_zeros = 0;
                }
                currentSum =  currentSum - nums[i];
                i++;
            }
            if(currentSum == goal){
                result += 1 + count_zeros;
            }
            j++;
        }
        return result;
    }
};