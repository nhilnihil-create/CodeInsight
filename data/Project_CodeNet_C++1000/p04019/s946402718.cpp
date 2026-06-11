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
    string s;
    int a[4]={0};
    cin>>s;
    for(auto x:s)
    {if(x=='N')a[0]++;else if(x=='S')a[1]++;else if(x=='W')a[2]++;else a[3]++;}
    if((a[1]>0 && a[0]==0)||(a[0]>0 && a[1]==0)||(a[2]>0 && a[3]==0)||(a[3]>0 && a[2]==0))
    cout<<"No";
    else
    cout<<"Yes";
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
