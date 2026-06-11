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
    int h,w;cin>>h>>w;
    char a[h][w];
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>a[i][j];
    for(int i=0;i<h;i++){for(int j=0;j<w;j++)cout<<a[i][j];cout<<endl;for(int j=0;j<w;j++)cout<<a[i][j];cout<<endl;}
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
