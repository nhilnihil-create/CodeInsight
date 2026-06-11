#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int w, a, b;
    cin >> w >> a >> b;
    if(a + w < b) cout << b - a - w << endl;
    else if(b + w < a) cout << a - b - w << endl;
    else cout << 0 << endl;
    
}