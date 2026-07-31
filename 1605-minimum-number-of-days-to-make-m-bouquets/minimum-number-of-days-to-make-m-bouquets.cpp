class Solution {
public:

    bool possible(vector<int>& bloomDay, int m, int k,int mid){
        int n = bloomDay.size();
        int count = 0;
        int NofD = 0;
        for(int i = 0; i<n; i++){
            if(bloomDay[i]<=mid){
                count+=1;
            }else{
                NofD += count/k;
                count = 0;
            }
        }
        NofD += count/k;
        return NofD >=m;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(bloomDay,m,k,mid) == true){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
        
    }
    
};