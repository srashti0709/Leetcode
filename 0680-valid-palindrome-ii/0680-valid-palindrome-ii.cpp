class Solution {
public:
    bool checkPalindrome(string s, int l, int r){
        while(l<r){
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
       
        while(l < r){
            while(l < r && !isalnum(s[l])) l++;
            while(l < r && !isalnum(s[r])) r--;
            if(tolower(s[l]) != tolower(s[r])){
               return checkPalindrome(s,l+1,r) || checkPalindrome(s,l,r-1);
            }    
            l++;
            r--;
        }
        return true;
   
    }
};