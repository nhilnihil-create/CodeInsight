#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int f[26]={0};
    for(int i=0;i<s.length();i++)
    {
        f[s[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(f[i]>0&&f[i]%2==1)
        {cout<<"No";return 0;}
    }
    cout<<"Yes";
    return 0;
}