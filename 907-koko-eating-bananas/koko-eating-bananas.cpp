class Solution {
public:
    long long time(vector<int>& piles,int r){
        long long Hourlytime = 0;
        for(int i =0; i<piles.size(); i++){
            Hourlytime += ceil((double)piles[i] / (double)r);
        }
        return Hourlytime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1; 
        int high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = low + (high - low)/2;
            long long totalH = time(piles,mid);
            if(totalH <= h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
        
    }
};