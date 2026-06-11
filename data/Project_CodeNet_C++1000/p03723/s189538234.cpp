#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int) n; i++)
#define repb(i, n) for (int i = (int) n; i >= 0; i--)
#define reps(i, m, n) for (int i = (int) m; i < (int) n; i++)
#define repsb(i, m, n) for (int i = (int) m; i >= (int) n; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.begin(), v.end(),greater<int>());
#define pb(a) push_back(a)
#define ll long long int
const ll LLINF = 1e18 + 10;
int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return 1; } return 0; }
template < class T > bool chmin(T & a,const T & b) { if (b < a) { a = b; return 1; } return 0; }
//vector<vector<int>> vec(n_rows, vector<int>(n_cols, value));
using namespace std;
int s(int a,int b,int c){
    if (a % 2 == 1 || b % 2 == 1||c % 2 == 1)
        return 0;
    if (a==b && b==c)
        return -1;

        return s((b + c) / 2, (a + c) / 2, (a + b) / 2) + 1;
}
int main(int argc, char const * argv[]){
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = s(a,b,c);
    cout<<ans<<endl;

    return 0;
}