#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

int calc(vector<int> a) {
    int n = a.size();
    int cnt = 0;
    rep(i, n-1) {
        if(a[i] == i+1) {
            swap(a[i], a[i+1]);
            cnt++;
        }
    }
    if(a.back() == n) cnt++;
    return cnt;
}

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = calc(a);
    reverse(all(a));
    rep(i, n) {
        a[i] = n - a[i] + 1;
    }
    ans = min(ans, calc(a));
    cout << ans << endl;
    return 0;
}