class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mpa;
        int n = A.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            mpa[A[i]]++;
            int temp = 0;
            for(int j = 0; j<= i;j++){
                if(mpa[B[j]] > 0) temp++; 
            }
            ans[i] = temp;
        }
        return ans;
    }
};