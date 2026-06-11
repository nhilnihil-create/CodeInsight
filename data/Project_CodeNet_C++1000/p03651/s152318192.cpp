#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
typedef vector<long long> vlint;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<vector<long long>> vlint2;



int main() {
    int n, k; cin >> n >> k;
    int a[n];
    int max_a = 0;
    rep(i, n){
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    int gcd_a = __gcd(a[0], a[1]);
    rep(i, n){
        gcd_a = __gcd(gcd_a, a[i]);
    }
    if (
        max_a < k || k % gcd_a != 0
        ){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << "POSSIBLE" << endl;
    }



}

