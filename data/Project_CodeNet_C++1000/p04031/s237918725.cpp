#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

vector<int> a;

int f(int k){
    int ret = 0;
    for(auto t : a){
        ret += (t-k)*(t-k);
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    a.resize(n);
    rep(i,n) cin>>a[i];
    int ans = 1e9;
    for(int i=-100; i<=100;i++){
        chmin(ans, f(i));
    }
    cout<<ans<<endl;
    return 0;


}