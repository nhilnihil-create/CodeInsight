#include<bits/stdc++.h>
#define int long long
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

int func(int n, int x){
    if(n == -1) return 0;
    else{
        return n/x + 1;
    }
}
signed main(){
    int a, b, x;
    cin >> a >> b >> x;
    cout << func(b, x) - func(a-1, x) << endl;
}