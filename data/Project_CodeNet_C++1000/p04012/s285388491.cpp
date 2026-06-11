#include<bits/stdc++.h>
using namespace std;


int main()
{

    string s;
    cin>>s;
    bool f=false;
    map<char,int>mp;
    for(int i=0;i<s.size();i++)
    {
        mp[s[i]]++;
    }
    for(auto x:mp)
    {
        if(x.second&1)
        {
            f=true;break;
        }
    }
    if(f)cout<<"No"<<"\n";
    else cout<<"Yes"<<"\n";
}

