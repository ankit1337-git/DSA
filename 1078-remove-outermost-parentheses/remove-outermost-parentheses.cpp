class Solution {
public:
    string removeOuterParentheses(string s) {
        string str = "";
        int count =0;
        for(char c: s){
            if(c == '('){
                count += 1;
                if(count > 1){
                    str += '(';
                }
            }else{
                count -= 1 ;
                if(count > 0){
                    str += ')';
                }

            }
        }
        return str;
        
    }
};