#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    int f=1;
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
    }
    for(auto i:mp)
    {
        if(i.second%2==1)
        {
            f=0;
            break;
        }
    }
    if(f==1)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}