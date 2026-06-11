//#include<bits/stdc++.h>
#include<iostream>
//#include<cstring>
#include<string>
//#include<vector>
#include<map>
//#include<queue>
//#include<stack>
#include<algorithm>
#define ll unsigned long long
#define endl "\n"
//#define eps 1e-9
using namespace std;
map<char,int>m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int f=0;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        char x=s[i];
        m[x]++;
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->second%2!=0)
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }


    return 0;
}
