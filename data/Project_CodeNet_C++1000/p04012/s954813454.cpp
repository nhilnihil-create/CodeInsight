#include <bits/stdc++.h>
using namespace std;

map<char,int>m;
map<char,int>::iterator it;
main()
{
    int i,j,k=1;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        m[s[i]]++;
    }
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second%2!=0)
        {
            k=0;break;
        }
    }
    if(k==0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    
}