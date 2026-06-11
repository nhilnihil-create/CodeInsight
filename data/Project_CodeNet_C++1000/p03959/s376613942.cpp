// Template
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

#define REP(i, n) for(int i = 0;i < n;i++)
#define INF 1 << 30

int MOD = 1000000007;

int main(){
    std::ios_base::sync_with_stdio(false);

    int n; cin >> n;
    std::vector<ll> left(n); REP(i,n) cin >> left[i];
    std::vector<ll> right(n); REP(i,n) cin >> right[i];

    std::vector<ll> l(n,0); l[0] = left[0];
    std::vector<ll> r(n,0); r[n-1] = right[n-1];
    for(int i=1; i<n;++i){
        if(left[i] != left[i-1]) l[i] = left[i];
        if(right[n-i] != right[n-i-1]) r[n-i-1] = right[n-i-1];
    }

    int ans = 1;

    // REP(i,n) cout << l[i] << " ";
    // cout << '\n';
    //
    // REP(i,n) cout << r[i] << " ";
    // cout << '\n';

    REP(i,n){
        if(l[i]!=r[i] && r[i]!=0 && l[i]!=0){
            cout << 0 << endl; return 0;
        }

        if(r[i]!=0 && left[i]<r[i]){
            cout << 0 << endl; return 0;
        }

        if(l[i]!=0 && right[i]<l[i]){
            cout << 0 << endl; return 0;
        }
    }

    REP(i,n){
        if(l[i]==0LL && r[i]==0LL){
            ans = ans * min(left[i], right[i]) % MOD;
        }
    }

    cout << ans << endl;





    return 0;
}
