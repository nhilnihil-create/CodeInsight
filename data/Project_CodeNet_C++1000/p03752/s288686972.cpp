#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <bitset>


using namespace std;

typedef long long ll;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<ll> vll;

typedef pair<int, int> P;

typedef queue<int> qi;
typedef queue<string> qs;


#define rep(i, n) for(int i=0; i<(n); ++i)
#define repp(i, a, b) for(int i = (a); i <= (b); i++)
#define Rep(i, n) for(int i=n; i >= 0; i--)

#define all(v) v.begin(), v.end()
//sort( all(v) )　などと使える

int n, k;
vll A;


int main(){
    cin >> n >> k;
    rep(i, n){
        ll a;
        cin >> a;
        A.push_back(a);
    }

    ll ans = pow(10, 16);

    rep(bit, (1 << n)){
        //
        if(__builtin_popcount(bit) < k) continue;
        //
        ll cost = 0;
        ll max_h = A[0];

        for(int i = 1; i < n; i++){
            if(bit & (1 << i)){
                cost += max(max_h - A[i] + 1, (ll)0);
                max_h = max(max_h + 1, A[i]);
            }

            else max_h = max(max_h, A[i]);

            

        }

        ans = min(ans, cost);
    }







    cout << ans << endl;
}