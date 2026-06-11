#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    set<char> se;
    rep(i, s.size())se.insert(s[i]);
    bool val = true;
    if((se.find('N')==se.end()) != (se.find('S')==se.end()))val = false;
    if((se.find('E')==se.end()) != (se.find('W')==se.end()))val = false;
    if(val)cout << "Yes" << endl;
    else cout << "No" << endl;
}