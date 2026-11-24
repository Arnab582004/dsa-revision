/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](Interval a , Interval b){
            return a.start<b.start;
        });
        for(int i=0;i<intervals.size();i++){
            //int st = intervals[i].start;
            int ed = intervals[i].end;
            for(int j=i+1;j<intervals.size();j++){
                int st = intervals[j].start;
                if(ed>st)return false;
            }
            
        }
        return true;
    }
};
