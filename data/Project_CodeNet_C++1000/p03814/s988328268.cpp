#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;
    cin>>s;

    int l=0,r=s.size()-1;

    for(int i=0;i<s.size();i++)if(s[i]=='A')
    {
        l=i;
        break;
    }

    for(int i=s.size()-1;i>=0;i--)if(s[i]=='Z')
    {
        r=i;
        break;
    }

    cout<<r-l+1<<"\n";

    return 0;
}
