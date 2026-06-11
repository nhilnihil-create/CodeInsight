#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int f4 = 0;
    int f2 = 0;
    int f0 = 0;
    rep(i, n){
        if(a[i] % 4 == 0) f4++;
        else if(a[i] % 2 == 0) f2++;
        else f0++;
    }
    if(f2 == 0 && f0 <= f4 + 1) cout << "Yes" << endl;
    else if(f0 <= f4) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}