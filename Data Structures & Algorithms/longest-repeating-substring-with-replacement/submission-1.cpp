class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int maxi=0,res=0;
        unordered_map<char,int>st;
        for(int r=0;r<s.size();r++){
            st[s[r]]++;
            maxi = max(maxi,st[s[r]]);
            while((r-l+1)-maxi>k){
                st[s[l]]--;
                l++;
            }
            res = max(r-l+1,res);
        }
        return res;
    }
};
