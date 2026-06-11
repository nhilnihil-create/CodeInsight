#include<iostream>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define endl "\n"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int mod = 1e9 + 7;
const string YES = "Yes";
const string NO = "No";
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    if(n > m/2){
        ans = m/2;
    }
    else{
        m -= n * 2;
        ans = n + (m / 4);
    }
    cout << ans << endl;
}