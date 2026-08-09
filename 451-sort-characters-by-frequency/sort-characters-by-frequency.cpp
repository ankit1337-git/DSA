class Solution {
public:
    string frequencySort(string s) {
        int count[256] = {0};
        for(char c: s){
            count[(unsigned char)c]++;
        }
        vector<pair<int,char>> freq;
        for(int i = 0; i<256; i++){
            if(count[i] > 0){
                freq.push_back({count[i],(char)i});

            }
            
        }
        sort(freq.rbegin(),freq.rend());

        string ans ="";
        for(auto it : freq){
            ans.append(it.first,it.second);
        }
        return ans;
    }
};