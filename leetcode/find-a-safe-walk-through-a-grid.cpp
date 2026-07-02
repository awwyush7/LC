class Solution {
public:

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, -1));
        vis[0][0] = 1;
        deque<vector<int>> dq;
        int temp = 0;
        if(grid[0][0] == 1) temp = 1;

        dq.push_back({0,0,temp});

        while(!dq.empty()){
            int k =dq.size();

            for(int i = 0;i< k;i++){
                auto node = dq.front();
                dq.pop_front();
                for(int i = -1;i<=1;i++){
                    for(int j = -1; j<= 1;j++){
                        if(i*j != 0) continue;
                        int nr = node[0] + i;
                        int nc = node[1] + j;
                        int h = node[2];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == -1){
                            if(nr == n-1 && nc == m-1){
                                if(grid[nr][nc] == 1){
                                    return h + 1 < health;
                            }else return h < health;
                            }
                            vis[nr][nc] = 1;
                            if(grid[nr][nc] == 1){
                                dq.push_back({nr,nc,h + 1});
                            }else dq.push_front({nr,nc,h});
                        }
                    }
                }
            }
        }
        return false;
    }
};