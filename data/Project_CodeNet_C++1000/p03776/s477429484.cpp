/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <utility>
#include <stack>
#include <bitset>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll MOD = 1e18;
ll INF = 1e18;


// 二項係数計算
long long COM(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    ll res=1LL;
    for(ll i=n,index=1;index<=k;i--,index++){
        res*=i;
        res/=index;
    }
  //  cout<<res<<endl;
    return res;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ld n,a,b;
    cin>>n>>a>>b;
    V vec(n);
    rep(i,n)cin>>vec[i];
    sort(all(vec),greater<ll>());
   // COMinit();
    set<ll> st;
    rep(i,a){
        st.insert(vec[i]);
    }
    if(st.size()!=1){
        ld sum=0;
        rep(i,a){
            ld k=vec[i];
            sum+=k;
        }
        sum/=a;
        cout<<setprecision(10)<<sum<<endl;
        ll temp=vec[a-1];
        ll res=0;
        ll sum1=0;
        rep(i,n){
            if(vec[i]==temp){
                if(i<a){
                    sum1++;
                }
                res++;
            }
        }
        cout<<COM(res,sum1)<<endl;
        return 0;
    }
    cout<<vec[0]<<endl;
    ll s=vec[0];
    ll sum=0;
    rep(i,n){
        if(s==vec[i]){
            sum++;
        }else{
            break;
        }
    }
    ll res=0;
    rep3(i,a,b+1){
      //  cout<<sum<<" "<<i<<" "<<COM(sum,i)<<endl;
        res+=COM(sum,i);
    }
    cout<<res<<endl;
}
