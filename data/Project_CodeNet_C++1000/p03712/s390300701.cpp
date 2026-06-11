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
    int n,m;
    cin>>n>>m;
    char a[n+2][m+2];
    for(int i=1;i<n+1;i++)
    for(int j=1;j<m+1;j++)
    cin>>a[i][j];
    
    for(int i=0;i<n+2;i++)
    {
        for(int j=0;j<m+2;j++)
        {
            //cout<<i<<" "<<j<<endl;
            if(i==0 || i==n+1 || j==0 || j==m+1)
            {
                cout<<"#";
            }
            else
            cout<<a[i][j];
        }
        cout<<endl;
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
