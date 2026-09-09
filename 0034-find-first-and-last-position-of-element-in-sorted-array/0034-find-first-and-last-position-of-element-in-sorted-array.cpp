class Solution {
public:
    int findleftMost(vector<int>& nums, int target, int n){
        int l = 0;
        int r = n-1;
        int leftMost = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target ){
                leftMost = mid;
                r = mid - 1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }

        }
        return leftMost;
    }
    int findrightMost(vector<int>& nums, int target, int n){
        int l = 0;
        int r = n-1;
        int rightMost = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target ){
                rightMost = mid;
                l = mid+1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }

        }
        return rightMost;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int leftMost = findleftMost(nums,target,n);
        int rightMost = findrightMost(nums,target,n);
        return {leftMost, rightMost};
    }
};