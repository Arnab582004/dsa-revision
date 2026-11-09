class Solution {
    vector<int>topoSort(int n , vector<int>adj[],bool present[]){
        int cnt=0;
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(present[i]){
                cnt++;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
        }
        if(topo.size()!=cnt)return {};
        return topo;
    }
public:
    string foreignDictionary(vector<string>& words) {
        int n = 26;
        vector<int>adj[26];
        bool present[26]={false};
        for(auto &word:words){
            for(auto &ch:word){
                present[ch-'a']=true;
            }
        }
        int ptr;
        for(int i=0;i<words.size()-1;i++){
            string s1 = words[i];
            string s2=words[i+1];
            int minlen = min(s1.size(),s2.size());
            for(ptr=0;ptr<minlen;ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
            if(ptr==minlen && s1.size()>s2.size())return "";
        }
        vector<int>topo = topoSort(n,adj,present);
        string ans="";
        for(auto it:topo){
            ans+=char(it+'a');
        }
        return ans;
    }
};
