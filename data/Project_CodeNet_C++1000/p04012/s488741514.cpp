#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int a[26]={0};
    for(int i=0;i<s.length();i++)
    {
        a[s[i]-'a']++;
    }
    bool p=true;
    for(int i=0;i<26;i++)
    {
        if(a[i]%2!=0)
        {
            p=false;
            break;
        }
    }
    if(p)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}





