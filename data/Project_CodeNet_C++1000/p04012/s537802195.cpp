#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int p=1;
    map<char,long long>m;
    set<char>so;
    set<char>::iterator it;
    for(int i=0;i<s.size();i++)
    {
        m[s[i]]+=1;
        so.insert(s[i]);
    }
    for(it=so.begin();it!=so.end();it++)
    {
        if(m[*it]%2!=0)
        {
            p=0;
            break;
        }
    }
    if(p==0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
}
