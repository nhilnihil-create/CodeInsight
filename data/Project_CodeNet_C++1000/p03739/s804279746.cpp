#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<long long,int> P;

int main(){
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];

    ll tmp1 = 0;
    ll cst1 = 0;
    rep(i, n){
        tmp1 += a[i];
        if (i % 2 == 0 && tmp1 <= 0) {
            cst1 += 1 - tmp1;
            tmp1 = 1;
        }
        else if (i % 2 != 0 && tmp1 >= 0) {
            cst1 += tmp1 + 1;
            tmp1 = -1;
        }
    }

    ll tmp2 = 0;
    ll cst2 = 0;
    rep(i, n){
        tmp2 += a[i];
        if (i % 2 != 0 && tmp2 <= 0) {
            cst2 += 1 - tmp2;
            tmp2 = 1;
        }
        else if (i % 2 == 0 && tmp2 >= 0) {
            cst2 += tmp2 + 1;
            tmp2 = -1;
        }
    }

    cout << min(cst1, cst2) << endl;
    return 0;
}