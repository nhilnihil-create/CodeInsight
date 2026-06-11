#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,a,b) for(int i=a;i<b;i++)
#define each(it,v) for(auto it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vv vector<vector<int>>
using namespace std;

main()
{
    int n,m,k; cin>>n>>m>>k;
    if(k==0||k==n*m)
    {
        cout<<"Yes"<<endl;
        return 0;
    }

    rep(i,n)
    {
        rep(j,m)
        {
            if((n*m-(i+1)*(j+1)-(n-i-1)*(m-j-1))==k)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}