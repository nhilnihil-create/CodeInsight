#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
const int mod = 1000000007;

int main() {
    ll Q,H,S,D;
    cin >> Q>>H>>S>>D;
    ll m = min(8*Q,min(4*H,min(2*S,D)));
    ll N;
    cin>> N;
    if(N%2==0){
        cout << m*(N/2) <<endl;
        return 0;
    }
    ll r = min(4*Q,min(2*H,S));
    cout << m*(N/2)+r <<endl;
    
}