class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
           
            sum+=nums[i];
           // maxi = max(maxi,sum);
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                if(nums.size()==1){
                    sum=-1;
                } 
                else{
                    sum=0;
                }
                
            }    
        }
        return maxi;
    }
};
