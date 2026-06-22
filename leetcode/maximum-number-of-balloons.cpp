class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a[5]={0};
        for(auto c: text){
            if(c=='b') a[0]++;
                if(c=='a') a[1]++;
            if(c=='l') a[2]++;
            if(c=='o') a[3]++;
            if(c=='n') a[4]++;
        }
        
        return min(min(min(min(a[2]/2,a[3]/2),a[4]),a[1]),a[0]);
    }
};