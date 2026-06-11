#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int mp[101010];
const int MOD = 1e9+7;

ll modpow(ll n, ll p, ll m) {
    ll res = 1;
    while(p>0){
        if(p%2==1) res = (res * n) % m;
        n = (n * n) % m;
        p /= 2;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> A(n);
    rep(i,n) cin>>A[i];
    rep(i,n) mp[A[i]]++;
    // 偶数ならば1~n-1, 奇数ならば0+2~n-1
    if(n%2){
        if(mp[0] != 1){
            cout<<0<<endl;
            return 0;
        }
        for(int i=2; i<=n-1; i+=2){
            if(mp[i]!=2){
                cout<<0<<endl;
                return 0;
            }
        }
    }else{
        for(int i=1;i<=n-1; i+=2){
            if(mp[i]!=2){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    cout<<modpow(2, n/2, MOD)<<endl;
    return 0;
}