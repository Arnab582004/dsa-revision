class Solution {
public:
    bool isPalindrome(string s) {
       string newstr = "";
       for(int i = 0 ; i<s.size();i++){
        char ch = s[i];
        if(ch >= 'a' && ch<= 'z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9'){
            newstr+=tolower(ch);
        }
       } 
      return newstr == string(newstr.rbegin(), newstr.rend());
    }
};
