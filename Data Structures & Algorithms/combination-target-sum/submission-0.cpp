class Solution {
    void printsum(int ind ,vector<int>&ds, vector<vector<int>>&ans ,  vector<int>&nums , int target,int n ){
        if(ind==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(nums[ind]<=target){
            ds.push_back(nums[ind]);
            printsum(ind,ds,ans,nums,target-nums[ind],n);
            ds.pop_back();
        }
        printsum(ind+1, ds,ans,nums,target,n);
        

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        int sum=0;
        int n = nums.size();
        printsum(0,ds,ans,nums,target,n);
        return ans;
    }
};
