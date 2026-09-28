class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        int l=0,reslen=INT_MAX,sIndex=-1,r=0;
        int m = t.size(),n=s.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        int count=0;
        while(r<n){
            if(mpp[s[r]]>0){
                count++;
            }
            mpp[s[r]]--;
            while(count==m){
                if((r-l+1)<reslen){
                    reslen = r-l+1;
                    sIndex = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0)count--;
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "":s.substr(sIndex,reslen);

    }
};
