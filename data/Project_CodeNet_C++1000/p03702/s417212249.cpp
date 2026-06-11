#include<bits/stdc++.h>
#define ll long long int
#define pragi(a,b) for(ll i = a;i<b;i++)
#define pragj(a,b) for(ll j = a;j<b;j++)
#define pragk(a,b) for(ll k = a;k>=b;k--)
#define all(v) (v.begin(),v.end())
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define KAKA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long double ld;
typedef pair<int, int> pii;
//typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
vector<ll> h;

bool predicate(ll x,ll a,ll b)
{
    ll sum = 0;
    ll n = h.size();
    
    pragi(0,n)
    {
        ll ele = h[i];
        ll lo = 0,hi = x;
        if((x * a) < h[i]) return false;
        while(lo < hi)
        {
            ll mid = lo + (hi - lo)/2;
            ll val = (mid * a) + ((x - mid)*b);
            if(val < ele) lo = mid + 1;
            else hi = mid;
        }
      sum += lo;
    }
   // cout<<sum<<" ";
    if(sum <= x) return true;
    else return false;
}
void Compute(ll n,ll a,ll b)
{
    KAKA
    h.resize(n);    
    pragi(0,n)
    {
        cin>>h[i];
    }
    //cout<<h[0]<<"\n";
    //Binary search the answer
    ll hmax = *max_element(h.begin(),h.end());
    ll lo = 1,hi = hmax/b + 1;
   //bool f1 =  predicate(15,a,b);
   //bool f2 = predicate(16,a,b);
   //bool f3 = predicate(14,a,b);
  // cout<<f3<<" "<<f1<<" "<<f2<<"\n";
    while(lo < hi)
    {
        ll mid = lo + (hi - lo)/2;
        if(predicate(mid,a,b)) hi = mid;
        else lo = mid + 1;
    }
    cout<<lo<<"\n";
}
int main()
{
    KAKA
    ll n,a,b;
    cin>>n>>a>>b;
    Compute(n,a,b);
}