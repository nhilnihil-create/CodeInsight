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
    string a,b;
    cin>>a>>b;
    if(a.length()>b.length())
    {
        cout<<"GREATER";return;
    }
    else if(b.length()>a.length())
    {
        cout<<"LESS";return;
    }
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>b[i])
        {
            cout<<"GREATER";return;
        }
        else if(a[i]<b[i])
        {
            cout<<"LESS";return;
        }
    }
    cout<<"EQUAL";
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
