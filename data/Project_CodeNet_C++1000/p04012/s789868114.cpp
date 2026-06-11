#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[26]={};
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        ++a[s[i]-'a'];
    for(int i=0;i<26;i++)
    {
        if(a[i]%2==1)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}

