class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
  int st=0,en=s.size()-1;
        while(st<en){
            if(s[st]!=s[en]) return false;
            st++;en--;
        }
        return true;
    }
};