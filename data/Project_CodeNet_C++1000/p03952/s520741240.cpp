#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define pi pair<int,int>
#define vi vector<int>
#define pL pair<ll,ll>
#define vL vector<ll>
#define vp vector<pi>
#define vpL vector<pL>

const int MX=1000000;
const ll inf=1e9;
const ll mod=998244353;


int a[MX];

int main()
{

    FasterIO;

    int n, m, x;

    cin>>n>>x;
    m=2*n-1;

    if(x==1 || x==m)
    {
        cout<<"No"<<endl; return 0;
    }

    cout<<"Yes"<<endl;

    a[n]=x;
    for(int i=n+1; i<=m; i++) x=x%m+1, a[i]=x;

    for(int i=1; i<n; i++) x=x%m+1, a[i]=x;

    for(int i=1; i<=m; i++) cout<<a[i]<<endl;

    return 0;
}
