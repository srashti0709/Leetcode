class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int product = 1;
        int count = 0;
        while(j<n){
            product = product * nums[j];
            while(product >= k){
                product = product / nums[i];
                i++;
            }
            count = count + (j-i+1);
            
            j++;
        }
        return count;
    }
};