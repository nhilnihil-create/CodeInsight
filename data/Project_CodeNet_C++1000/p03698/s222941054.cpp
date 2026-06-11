#include<bits/stdc++.h>
using namespace std;
bool comp(pair<long long int,long long int>a,pair<long long int,long long int>b)
{
    if(a.first==b.first)
    {
        if(a.second<=b.second)
        return true;
        else
        return false;
    }
    if(a.first>b.first)
    return true;
    else return false;
}
long long int gcd(long long int bdda,long long int chota)
{
    if(chota==0)
        return bdda;
    return gcd(chota,bdda%chota);
}
void solve()
{
    map<char,int>mp;
    string s;
    cin>>s;
    int n=s.length();
    for(long long int i=0;i<n;i++)
    {
        char ch=s[i];
        if(mp[s[i]]!=0)
        {
            cout<<"no";
            return;
        }
        else
        mp[ch]=1;
    }
    cout<<"yes";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;

    //cin>>t;
    while(t--)
    {
        solve();
    }
}
