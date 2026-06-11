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
    long long int a,b,c;
    cin>>a>>b>>c;
    long long int num=0;
    while(true){
        if(a%2==1||b%2==1||c%2==1){
            cout<<num;return ;
        }
        if(a==b&&b==c){
            cout<<-1;return ;
        }
        ++num;
        long long int x,y,z;
        x=(b/2+c/2);y=(a/2+c/2);z=(a/2+b/2);
        a=x;b=y;c=z;
    }
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
