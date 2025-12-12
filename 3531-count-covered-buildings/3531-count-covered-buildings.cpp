class Solution {
public:
    int countCoveredBuildings(int k, vector<vector<int>>& b) {
        int n=b.size();

        unordered_map<int,vector<int>>mpx;
        unordered_map<int,vector<int>>mpy;
        set<pair<int,int>>s;

        for(int i=0;i<n;i++){
            mpx[b[i][0]].push_back(b[i][1]);
            mpy[b[i][1]].push_back(b[i][0]);
        }

        for(auto &ele:mpx){
            int x=ele.first;
            vector<int>v=ele.second;
            sort(v.begin(),v.end());
            s.insert({x,v[0]});
            s.insert({x,v.back()});
        }
        for(auto &ele:mpy){
            int y=ele.first;
            vector<int>v=ele.second;
            sort(v.begin(),v.end());
            s.insert({v[0],y});
            s.insert({v.back(),y});
        }
        return n-s.size();

    }
};