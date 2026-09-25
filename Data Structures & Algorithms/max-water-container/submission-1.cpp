class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = INT_MIN;
        int l=0,r=n-1;
        while(l<r){
            int width = r-l;
            int height = min(heights[r],heights[l]);
            int area = width * height;
            maxi = max(maxi,area);
            if(heights[l]<=heights[r]){
                l++;
            }
            else{
                r--;
            }
            
        }
            
        
        return maxi;
    }
};
