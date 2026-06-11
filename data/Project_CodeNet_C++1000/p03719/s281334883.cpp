#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(c >= a && c <= b) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}