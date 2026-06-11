#include <bits/stdc++.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll q,h,s,d,n;
    cin >> q >> h >> s >> d >> n;
    s = min({s,2*h,4*q});
    if(2*s <= d){
        cout << n*s << endl;
    }else{
        cout << (n/2)*d + (n%2)*s << endl;
    }
    return 0;
}