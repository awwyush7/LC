class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int> dis(n, INT_MAX);
        vector<vector<pair<int,int>>> graph(n);
        vector<vector<pair<int,int>>> inc(n);
        for(auto c : edges){
            graph[c[0]].push_back({c[1],c[2]});
            graph[c[1]].push_back({c[0], 2*c[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        dis[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int diss = p.first;
            for(auto c : graph[node]){
                if(dis[c.first] > diss + c.second){
                    dis[c.first] = diss + c.second;
                    pq.push({dis[c.first], c.first});
                }
            }
            for(auto c : inc[node]){
                if(dis[c.first] > diss + c.second){
                    dis[c.first] = diss + c.second;
                    pq.push({dis[c.first], c.first});
                }
            }
        }
        if(dis[n-1] == INT_MAX) return -1;
        return dis[n-1];
    }
};