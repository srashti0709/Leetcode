class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length() > n){
            return "";
        }
        unordered_map<char,int> mp;
        //map me store kar liya
        for(char &ch:t){
            mp[ch]++;
        }
        int requiredCount = t.length();
        int i = 0;
        int j = 0;
        int minWindowSize = INT_MAX;
        int start_i = 0;
        //story starts
        while(j < n){
            char ch = s[j];
            if(mp[ch] > 0){
                requiredCount --;
            }
            mp[ch]--;
            while(requiredCount == 0){
                //start Shrinking the window
                int currentWindowSize = j-i+1;
                if(minWindowSize > currentWindowSize){
                    minWindowSize = currentWindowSize;
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }
        if(minWindowSize == INT_MAX){
            return "";
        }
        else{
            return s.substr(start_i,minWindowSize);
        }
    }
};