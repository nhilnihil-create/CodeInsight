#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int k,t;cin >> k >> t;
    vi a(t);
    rep(i,t) cin >> a[i];
    sort(a.begin(),a.end());
    int l = 0,r = t-1;
    while(l!=r){
        if(a[r] - a[l] >0){
            a[r] -= a[l];
            ++l;
        }
        else if(a[r] - a[l] <= 0){
            a[l] -= a[r];
            --r;
        }
    }
    if(a[l]>0) cout << a[l]-1 << endl;
    else cout << 0 << endl;
}