class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=0;
        int n = intervals.size();
        vector<vector<int>>ans;
        vector<int>newInterval=intervals[0];
        if(n==0)ans;
        //if(intervals[1][0]==0 && intervals[1][0]==0)return ans;
        while(i<n-1){
            if(newInterval[1]>=intervals[i+1][0]){
                newInterval[0] = min(newInterval[0] , intervals[i+1][0]);
                newInterval[1] = max(newInterval[1],intervals[i+1][1]);
            }
            else{
                 ans.push_back(newInterval);
                 newInterval = intervals[i+1];
            }
            i++;
        }
        ans.push_back(newInterval);
        // while(i<n && intervals[i][1]>=intervals[i+1][0]){
        //     newInterval[0] = min(intervals[i][0] , intervals[i+1][0]);
        //     newInterval[1] = max(intervals[i][1],intervals[i+1][1]);
        //     i+=1;
        // }
       // ans.push_back(newInterval);
        
        return ans;
    }
};
