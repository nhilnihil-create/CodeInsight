#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int ans=s.length()/2;
    for(int i=0;i<s.length();i++)
        if(s[i]=='p')
            ans--;
    cout<<ans;
    return 0;
}

