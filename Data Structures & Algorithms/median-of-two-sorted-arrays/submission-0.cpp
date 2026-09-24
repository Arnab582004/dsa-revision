class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged;
        int l=0,r=0;
        double median;
        int m = nums1.size();
        int n = nums2.size();
        while(l<m){
            merged.push_back(nums1[l]);
            l++;
        }
        while(r<n){
            merged.push_back(nums2[r]);
            r++;
        }
        sort(merged.begin(),merged.end());
        int s = merged.size();
        if(s%2==1){
            return (double)merged[s/2];
        }
        return (double)(merged[s/2-1]+merged[s/2])/2.0;
    }
};
