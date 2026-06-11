#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t,a,b,i,j,k,n;
    string s;
    cin>>s;
    map<char,ll>m;
    for(i=0;i<s.length();i++)
    {
        m[s[i]]++;
    }
    for(i=0;i<s.length();i++)
    {
        if(m[s[i]]%2==1)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
