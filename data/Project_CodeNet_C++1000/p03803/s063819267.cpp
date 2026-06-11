#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    if(a == 1) a = 14;
    if(b == 1) b = 14;
    if(a > b) cout << "Alice" << endl;
    else if(a < b) cout << "Bob" << endl;
    else cout << "Draw" << endl;
    return 0;
}