class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        string ans = "";

        int min_length = min(first.size(),last.size());
        for(int i = 0; i<min_length; i++){
            if(first[i] != last[i]){
                break;
            }else{
                ans += first[i];
            }
            


        }
        return ans;

        
    }
};