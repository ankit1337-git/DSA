class Solution {
public:

    int row_index(vector<vector<int>>& mat, int mid){
        int n = mat.size();
        int max = -1;
        int index = -1;
        for(int i = 0; i<n; i++){
            if(mat[i][mid] > max){
                max = mat[i][mid];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat[0].size();
        int n = mat.size();

        int low = 0;
        int high = m-1;

        while(low<=high){
            int mid = low+(high-low)/2;
            int row = row_index(mat,mid);
            int left = mid-1 >= 0? mat[row][mid-1]:-1;
            int right = mid+1 < m? mat[row][mid+1]:-1;

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }else if(mat[row][mid] < left){
                high = mid-1;
            }else{
                low = mid+1;
            }

        }
        return {-1,-1};
        
    }
};