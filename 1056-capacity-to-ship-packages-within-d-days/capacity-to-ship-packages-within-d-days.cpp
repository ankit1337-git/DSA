class Solution {
public:

    int possible(vector<int>& weights, int days,int mid){
        int day = 1;
        int load = 0;
        int n = weights.size();
        for(int i = 0; i<n; i++){
            if(load+weights[i] <= mid){
                load += weights[i];

            }else{
                day = day+1;
                load = weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            int noOfdays = possible(weights,days,mid);
            if(noOfdays <= days){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};