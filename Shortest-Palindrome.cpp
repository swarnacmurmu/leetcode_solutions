class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string temp=s+"#"+rev;
        int n=temp.size();
        vector<int>lps(n,0);
        int len=0;
        int i=1;
        while(i<n){
            if(temp[i]==temp[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len != 0){
                    len=lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        int palindromePrefixLength=lps[n-1];
        string remaining=s.substr(palindromePrefixLength);
        reverse(remaining.begin(),remaining.end());
        return remaining + s;
        
    }
};
