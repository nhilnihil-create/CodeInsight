#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
#include <iomanip>
#include <queue>
#include <cmath>

using namespace std;
using ll = long long;
using pa = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e14;
const long double EPS = 1e-11;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (int i = (l); i < (r); i++)
#define reper(i, l, r) for (int i = (r)-1; i >= (l); i--)

void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
}
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll H,W;
    cin>>H>>W;
    ll x,y;
    rep(i,H)rep(j,W){
    	string s;
    	cin>>s;
    	if(s=="snuke"){
    		x=j,y=i+1;
    	}
    }
    cout<<(char)('A'+x)<<y<<endl;
    return 0;
}
