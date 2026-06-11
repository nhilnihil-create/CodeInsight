
#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pqb             priority_queue<ll>
#define pqs             priority_queue<ll,vi,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            ll x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
vector<ll>vp;


int main()
{
    FIO;
    ll a,b,c,d,e,f=0,sum=0,ck=0,m,n,k,l,t1=-1,t2=-1,p,q,r,t,add=0,x,y,z;
   vector<pii>v;
   cin>>n;
   for(int i=0;i<2*n;i++){
    cin>>l;
    vp.pb(l);
   }
   sort(vp.begin(),vp.end());
   for(int i=0;i<2*n;i++){
        if(i%2==0){
    sum+=vp[i];}
   }
  cout<<sum<<endl;
  vp.clear();
    return 0;
}

