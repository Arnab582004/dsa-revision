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
        if(!intervals.size())return true;
        sort(intervals.begin(),intervals.end(),[](Interval a , Interval b){
            return a.start<b.start;
        });
        for(int i=0;i<intervals.size()-1;i++){
            //int st = intervals[i].start;
            int ed = intervals[i].end;
            int st = intervals[i+1].start;
            if(ed>st)return false;
        }
        return true;
    }
};
