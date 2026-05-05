class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> temp(n,vector<int>(m,0));
        priority_queue<int, vector<int>, greater<int> > pq;
        int xorr;

        xorr = temp[0][0] = matrix[0][0];
        pq.push(temp[0][0]);

        for(int i=1;i<m;i++){
            xorr = xorr ^ matrix[0][i];
            temp[0][i] = xorr;
            pq.push(xorr);
            if(pq.size() > k) pq.pop();
        }
        xorr = matrix[0][0];
        for(int i=1;i<n;i++){
            xorr = xorr ^ matrix[i][0];
            temp[i][0] = xorr;
            pq.push(xorr);
            if(pq.size() > k) pq.pop();
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                temp[i][j] = temp[i-1][j] ^ temp[i][j-1] ^ temp[i-1][j-1] ^ matrix[i][j];
                pq.push(temp[i][j]);
                if(pq.size() > k) pq.pop();
            }
        }
        // for(auto c : temp){
        //     for(auto a : c){
        //         cout<<a<<" ";
        //     }
        //     cout<<"\n";
        // }
        return pq.top();
    }
};