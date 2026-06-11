#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    str s;
    cin>>s;

    int ans=0;
    int x=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='I')x++;
        else if(s[i]=='D')x--;
        ans=max(ans,x);
    }

    cout<<ans<<"\n";

    return 0;
}
