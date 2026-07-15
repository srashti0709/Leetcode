class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // first store the row wise cumulative sum
        for(int i = 0; i < rows; i++){
            for(int j = 1; j < cols; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        // now find the no. of subarrays with sum == target (Downwards direction)
        int result = 0;
        for(int startCol = 0; startCol < cols; startCol++){
            for(int j = startCol; j < cols; j++){
                unordered_map<int,int>mp;
                mp[0] = 1;
                int CumSum = 0;
                for(int row = 0; row<rows;row++){
                    CumSum += matrix[row][j] - (startCol > 0 ? matrix[row][startCol-1] : 0);
                    if(mp.find(CumSum - target) != mp.end()){
                        result += mp[CumSum - target];
                    }
                    mp[CumSum]++;
                }
            }
        }
        return result;

    }
};