class Solution {
    public int[] findErrorNums(int[] nums) {
        Arrays.sort(nums);

        int dup = -1;
        int mis = -1;

        // case: missing 1
        if (nums[0] != 1) {
            mis = 1;
        }

        for (int i = 0; i < nums.length - 1; i++) {

            // duplicate
            if (nums[i] == nums[i + 1]) {
                dup = nums[i];
            }

            // missing in between
            if (nums[i + 1] != nums[i] + 1 && nums[i] != nums[i + 1]) {
                mis = nums[i] + 1;
            }
        }

        // case: missing n
        if (mis == -1) {
            mis = nums.length;
        }

        return new int[]{dup, mis};
    }
}