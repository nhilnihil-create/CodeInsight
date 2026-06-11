#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int a, b;
    cin >> a >> b;
    if(a == b) cout << "Draw" << endl;
    else if(a == 1) cout << "Alice" << endl;
    else if(b == 1) cout << "Bob" << endl;
    else{
        cout << ((a > b) ? "Alice" : "Bob") << endl;
    }
    
}