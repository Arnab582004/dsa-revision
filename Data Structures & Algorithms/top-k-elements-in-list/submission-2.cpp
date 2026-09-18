class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<int>ans;
       // if(k==nums.size()) return nums;
        for(int num:nums){
            mpp[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(const auto &it:mpp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            int ele = pq.top().second;
            pq.pop();
            ans.push_back(ele);
        }
        return ans;
    }
};
