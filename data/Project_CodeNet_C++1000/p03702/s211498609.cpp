#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可
//乗算の際にオーバーフローに注意せよ！！（適切にmodをとれ）

const ll INF=1e18;

signed main(){
    int n;
    cin>>n;
    ll a,b;
    cin>>a>>b;
    V<ll> h(n);
    cinf(n,h);
    sort(all(h));
    ll left=-1,right=1e9+1;
    while(right-left>1){
        ll mid=(left+right)/2;
        ll cnt=0;
        bool ok=1;
        for(int i=0;i<n;i++){
            if(b*mid>=h[i]) continue;
            ll u;
            if((h[i]-b*mid)%(a-b)==0) u=(h[i]-b*mid)/(a-b);
            else u=(h[i]-b*mid)/(a-b)+1;
            cnt+=u;
            if(cnt>mid){
                ok=0;
                break;
            }
        }
        if(ok) right=mid;
        else left=mid;
    }
    cout<<right<<endl;
}