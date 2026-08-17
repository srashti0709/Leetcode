class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCount(26,0);
        for(char &ch : chars){
            charCount[ch - 'a']++;

        }
        int result = 0;
        for(string &word : words){
            vector<int> WordCount(26,0);
            for(char &ch : word){
                WordCount[ch-'a']++;
            }
            bool good = true;
            for(int i = 0;i<26;i++){
                if(WordCount[i] > charCount[i]){
                    good = false;
                    break;
                }
            }
            if(good == true){
                result +=  word.length();
            }
        }
        return result;
    }
};