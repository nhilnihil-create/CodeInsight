#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template < typename T > string tost( const T& n ) { ostringstream stm; stm << n; return stm.str();}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int x,y;
cin >> x >> y;

int ans;
if(x == 0) {
    if(y >= 0) ans = y;
    else ans = abs(y)+1;
}
else if(y == 0) {
    if(x < 0) ans = abs(x);
    else ans = x+1;
}
// |x|>=1 and |y|>=1
else {
    if(abs(x) < abs(y)) {
        int cnt = 0;
        if(x < 0) cnt++;
        if(y < 0) cnt++;
        ans = abs(y) - abs(x) + cnt;
    }
    else if(abs(x) > abs(y)) {
        int cnt = 0;
        if(x > 0) cnt++;
        if(y > 0) cnt++;
        ans = abs(x) - abs(y) + cnt;
    }
    else {
        if(x == y) ans = 0;
        else ans = 1;
    }
}
cout << ans << endl;
return 0;
}