

#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isev(string &s,ll x)
{
    if(x&1) return 0;
    for(int i=0;i<x/2;i++)
    {
        if(s[i]!=s[x/2+i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string s;
    cin>>s;
    ll n=s.size();
    n--;
    while(isev(s,n)==0)
    {
        n--;
    }
    cout<<n<<endl;

}
