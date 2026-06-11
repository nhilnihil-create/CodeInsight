#include <bits/stdc++.h>
using namespace std;

using str = string;
using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    str s;cin>>s;
    
    int ans=s.size();
    
    for(int i=s.size()-2;i>0;i-=2)
    {
        bool c=true;
        ans-=2;
        for(int j=0;j<i/2;j++)if(s[j]!=s[j+i/2])c=false;
        if(c)break;
    }
    
    cout<<ans<<"\n";
    
    return 0;
}

