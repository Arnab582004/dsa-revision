class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int l = 0;
        unordered_set<char>st;
        for(int r = 0 ;r<s.size();r++){
            while(st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxi  = max(maxi , r-l+1);
        }
        return maxi;
    }
};
