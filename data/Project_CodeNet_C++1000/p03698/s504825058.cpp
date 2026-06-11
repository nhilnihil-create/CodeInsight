#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool f[27]={};
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(!f[s[i]-'a'])
        {
            f[s[i]-'a']=true;
        }
        else
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}

