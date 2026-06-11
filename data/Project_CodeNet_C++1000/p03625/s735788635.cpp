#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n)cin>> a[i];
    map<ll,ll>x;
    rep(i,n){
        ll now = a[i];
        x[now]++;
    }
    vector<ll>k;
    vector<ll>s;
    for(auto itr=x.begin();itr!=x.end();itr++){
        if((itr->second)>=2){
            k.push_back(itr->first);
        }
        if((itr->second)>=4){
            s.push_back(itr->first);
        }
    }
    sort(k.begin(),k.end());
    reverse(k.begin(),k.end());
    sort(s.rbegin(),s.rend());
    ll res=0;
    if((ll)k.size()<=1&&(ll)s.size()==0){
        cout << 0 << endl;
    }
    else{
    if(s.size()!=0){
        res = s[0]*s[0];
    }
    if(k.size()>=2){
        chmax(res,k[0]*k[1]);
    }
    cout << res << endl;
    }
    return 0;
}
