#include <bits/stdc++.h>
using namespace std;

int n, nextpos[200010][26];
unsigned int memo[200010];

unsigned int getMinimumLength(int i)
{
    if (i>n) return 0;
    auto& res=memo[i];
    if (~res) return res;
    for(int c=0; c<26; ++c)
        res=min(res, getMinimumLength(nextpos[i][c]+1)+1);
    return res;
}

int main()
{
    string s; cin>>s;
    n=s.size();

    for(int c=0; c<26; ++c) nextpos[n][c]=n+1;
    for(int i=n-1; i>=0; --i)
        for(int c=0; c<26; ++c)
            nextpos[i][c]=s[i]==c+'a' ? i : nextpos[i+1][c];

    memset(memo, -1, sizeof(memo));

    string res(n+1, '~');
    for(int i=0; i<26; ++i) {
        string t(1, i+'a');
        int k=nextpos[0][i]+1;
        while (k<=n) {
            int L=n+n, c;
            for(int j=0; j<26; ++j) {
                if (L>getMinimumLength(nextpos[k][j]+1)+1) {
                    L=getMinimumLength(nextpos[k][j]+1)+1;
                    c=j;
                }
            }
            t+=char(c+'a');
            k=nextpos[k][c]+1;
        }
        if (res.size()>t.size() || res>t) res=t;
    }
    cout<<res<<endl;
}
