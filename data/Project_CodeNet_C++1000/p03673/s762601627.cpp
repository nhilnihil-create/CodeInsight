#include<bits/stdc++.h>
/* #define int long long */
/* #define double long double */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll start, end;
    if(n % 2){
        /* n が奇数 */
        start = n-1;
        end = n-2;
        for(int i = start; i >= 0; i -= 2){
            cout << a[i] << " ";
        }
        for(int i = 1; i <= end; i += 2){
            cout << a[i] << " ";
        }
    }else{
        /* 偶数 */
        start = n-1;
        end = n-2;
        for(int i = start; i >= 1; i -= 2){
            cout << a[i] << " ";
        }
        for(int i = 0; i <= end; i += 2){
            cout << a[i] << " ";
        }
    }
    cout << endl;
}