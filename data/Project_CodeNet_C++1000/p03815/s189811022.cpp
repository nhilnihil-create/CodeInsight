#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    ll x;
    cin >> x;
    ll ans = 0;
    ans += (x/11)*2;
    if(x%11==0) ans += 0;
    else if(x%11<=6) ans += 1;
    else ans += 2;
    cout << ans << endl;
    
}