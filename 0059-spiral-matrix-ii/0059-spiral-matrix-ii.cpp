class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int cnt = 1;
        int top = 0, bottom = n-1, left = 0, right = n-1;
        while(top <= bottom && left <= right){
            for(int col = left; col <= right; col++){
                matrix[top][col] = cnt++;
            }
            top++;
            for(int row = top; row <= bottom; row++){
                matrix[row][right] = cnt++;
            }
            right--;
            if(right >= left){
                for(int col = right; col >= left; col--){
                    matrix[bottom][col] = cnt++;
                }
                bottom--;
            }
            if(top <= bottom){
                for(int row = bottom; row >= top; row--){
                    matrix[row][left] = cnt++;
                }
                left++;
            }
        }
        return matrix;
    }
};