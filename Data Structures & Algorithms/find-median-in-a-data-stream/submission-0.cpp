class MedianFinder {
    private:
        priority_queue<int>lower;
        priority_queue<int,vector<int>,greater<int>> upper;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lower.push(num);
        upper.push(lower.top());
        lower.pop();
        if(upper.size()>lower.size()){
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if(lower.size()==upper.size()) return lower.top()/2.0 + upper.top()/2.0;
        return lower.top();
    }
};
