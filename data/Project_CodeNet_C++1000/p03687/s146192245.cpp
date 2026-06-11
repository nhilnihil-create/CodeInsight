#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

#define fi first
#define se second

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;cin>>s;

    int ans=1000;

    for(int i=0;i<26;i++)
    {
        int maxn=0;
        int pos=-1;
        for(int j=0;j<s.size();j++)if(s[j]==i+'a')
        {
            maxn=max(maxn,j-pos-1);
            pos=j;
        }
        maxn=max(maxn,(int)(s.size()-pos-1));
        ans=min(ans,maxn);
    }

    cout<<ans<<"\n";

    return 0;
}
