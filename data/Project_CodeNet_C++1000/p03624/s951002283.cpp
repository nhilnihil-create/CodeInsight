#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int a[26];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;
    cin>>s;

    for(int i=0;i<s.size();i++)a[s[i]-'a']++;
    
    char ans=0;

    for(int i=0;i<26;i++)if(a[i]==0)
    {
        ans=i+'a';
        break;
    }

    if(ans==0)cout<<"None\n";
    else cout<<ans<<"\n";

    return 0;
}
