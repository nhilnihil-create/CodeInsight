#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int x, y;
    cin >> x >> y;
    set<int> a = {1, 3, 5, 7, 8, 10, 12};
    set<int> b = {4, 6, 9, 11};
    if(a.find(x) != a.end() && a.find(y) != a.end()) cout << "Yes" << endl;
    else if(b.find(x) != b.end() && b.find(y) != b.end()) cout << "Yes" << endl;
    else cout << "No" << endl;
}