#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);



int main(){
    FIN;

    ll n; cin >> n;
    ll k; cin >> k;
    vector<char> d(k);
    for(int i=0;i<k;i++) cin >> d[i];
    ll ans;

    for(ll i=n;;i++){
        string s;
        s = to_string(i);
        bool ok = true;
        for(int j=0;j<s.size();j++){
            for(int m=0;m<k;m++){
                if(s[j] == d[m]) ok = false;
            }
        }
        if(ok){
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
