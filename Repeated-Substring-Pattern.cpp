class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        vector<int>lps(n,0);
        int len=0;
        int i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0)
                    len=lps[len-1];
                else
                    i++;
            }
        }
        int longestPrefixSuffix=lps[n-1];
        return (longestPrefixSuffix >0 && n%(n - longestPrefixSuffix)==0);
    }
};
