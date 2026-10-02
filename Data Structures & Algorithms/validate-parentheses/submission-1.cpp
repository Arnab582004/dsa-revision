class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        char ch;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                 st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                ch = st.top();
                st.pop();
                if(s[i]==')' && ch!='(' || s[i]=='}' && ch!='{'|| s[i]==']' && ch!='['){
                    return false;
                }
            }
        }
        return st.empty();
    }
};
