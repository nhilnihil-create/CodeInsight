#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl "\n"
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    ll x, y;
    cin >> x >> y;
    ll ans = INT_MAX;

    if(x<=y){
        ans = min(ans, y-x);
    }
    if(-x <= y){
        ans = min(ans, 1+y-(-x));
    }
    if(x<=-y){
        ans = min(ans, 1-y-x);
    }
    if(-x <= -y){
        ans = min(ans, 2-y+x);
    }
    cout << ans;
}
