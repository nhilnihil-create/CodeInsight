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
    int a,b,c;
    cin >> a>>b>>c;
    int ans = 0;
    rep(i,31){
        if(a%2==1||b%2==1||c%2==1){
            cout << ans << endl;
            return 0; 
        }
        int A = a;
        int B = b;
        int C = c;
        a = (B+C)/2;
        b = (A+C)/2;
        c = (B+C)/2;
        ans++;
    }
    cout << -1 <<endl;
}