#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll s,c;cin>>s>>c;
    ll ans = 0;
    if(s*2>c){
        ans =  c/2;
    }
    else {
        ans = s;
        c -= s*2;
        ans += c/4;
    }
    cout<<ans<<endl;
}