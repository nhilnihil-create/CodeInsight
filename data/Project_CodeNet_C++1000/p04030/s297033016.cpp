#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string s,ans="";
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='B')
            ans+=s[i];
        else
        {
            if(ans.size()>0)ans.pop_back();
        }
    }
    cout<<ans<<"\n";
}
