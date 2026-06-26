class Solution {
public:
    string reverseWords(string s) {
        //1. reverse whole string
        reverse(s.begin(),s.end());
        int i = 0;
        // hero honge hmare l and r jo reverse karenge words ko
        int l = 0;
        int r = 0;
        int n = s.length();
        //i hamesha travel karta rahega
        while(i<n){
            // jab tk i ko character milta rahega.. means not equal to space
            while(i<n && s[i]!=' '){
                //i ko agar char dikha toh r ko dega or phir i++ and r++
                s[r] = s[i];
                i++;
                r++;
            }
            // jab i ko space milega tab i ruk jayega or bolega l or r tum dono reverse kar lo
            if( l < r){
                reverse(s.begin()+l,s.begin()+r);
                // r apne pass ek space dalega phir r++ hojayega
                s[r] = ' ';
                r++;
                // l ko r k pass le ayege
                l = r;
            }
            i++;
        }
        s = s.substr(0,r-1);
        return s;
    }
};