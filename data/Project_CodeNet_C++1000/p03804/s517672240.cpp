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
    ll n,m; cin >> n >> m;
    vector<string> A(n);
    vector<string> B(m);
    for(ll i=0;i<n;i++) cin >> A[i];
    for(ll i=0;i<m;i++) cin >> B[i];
    bool ok = false;

    for(ll i=0;i<n-m+1;i++){
        for(ll j=0;j<n-m+1;j++){
            ll flag = 0;
            //左上のマスがi,j
            for(ll k=0;k<m;k++){
                if(A[i+k].substr(j,m) == B[k]) flag++;
            }
            if(flag == m) ok = true;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
