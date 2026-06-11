#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

unordered_map<int, int> memo;

int main() {
    int n;
    cin >> n;
    rrep(i, n) {
        int a;
        cin >> a;
        memo[i] = a;
    }
    int ans = 0;
    rrep(i, n) {
        if(memo[memo[i]] == i) ans++;
    }
    ans /= 2;
    cout << ans << endl;
    
    return 0;
}