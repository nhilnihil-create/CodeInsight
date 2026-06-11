#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define ll          long long int
#define T           long long int t;scanf("%lld",&t);while(t--)
#define CS          cout<<"Case "<<cs++<<": "
#define nd          endl
#define dd          double
#define ss          string
#define Y           cout<<"YES"<<endl
#define N           cout<<"NO"<<endl
#define for0(i,n)   for( i=0;i<n;i++)
#define forn(n,i)   for( i=n-1;i>=0;i--)
deque<ll>dq;
vector<ll>v;
map<ll,ll>m;


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    ll n,m,a,b,k,j,sum=0,sum1=0,i=1,even=0,odd=0,temp=0,temp1=0;
    ss s,s1;
    ll mod=1e9 +7;
    cin>>n;
    while(n>0)
    {
        n=n-i;
        sum++;
        i++;
    }
    cout<<sum;
    return 0;
}

