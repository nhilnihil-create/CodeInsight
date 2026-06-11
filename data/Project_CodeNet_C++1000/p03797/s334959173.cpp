#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    if(n>=1 && m>=2) {
        ll lim = m/2;
        ans += min(n,lim); //まずsのピースを使えるだけ使い切る
        m -= 2*min(n,lim);
    }
    ans += m/4;
    cout << ans << endl;
    
}