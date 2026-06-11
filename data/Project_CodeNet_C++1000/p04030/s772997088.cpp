#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;cin>>s;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='B')
        {
            s[i]='2';
            for(int j=i;j>=0;j--)if(s[j]=='0'||s[j]=='1'){s[j]='2';break;}
        }
    }

    str ans="";
    for(int i=0;i<s.size();i++)if(s[i]=='0'||s[i]=='1')ans.push_back(s[i]);

    cout<<ans<<"\n";

    return 0;
}
