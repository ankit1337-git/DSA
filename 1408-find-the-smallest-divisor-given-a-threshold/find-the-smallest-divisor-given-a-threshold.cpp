class Solution {
public:

    bool possible(vector<int>& nums, int threshold,int mid){
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += (nums[i]+mid-1)/mid;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(threshold < n){
            return -1;
        }
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(possible(nums,threshold,mid) == true){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};