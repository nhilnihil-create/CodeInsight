#include<iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, x, n) for (int i = x; i < (n); ++i)
using namespace std;

// using ll = long long;
// using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int size = (int) s.size();

    string res = s[0] + to_string(size-2) + s[size-1];

    cout << res << endl;
    return 0;
}
