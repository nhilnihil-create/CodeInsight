#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    if(n / 100 == n % 10) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}