#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
int main() {
string s;
cin >> s;
ll north = count(s.begin(), s.end(), 'N');
ll south = count(s.begin(), s.end(), 'S');
ll east = count(s.begin(), s.end(), 'E');
ll west = count(s.begin(), s.end(), 'W');
bool flaga = false;
if (north * south == 0) {
    if (north == 0 && south == 0) flaga = true;
    else {
        cout << "No" << endl;
        return 0;
    }
}
bool flagb = false;
if (east * west == 0) {
    if (east == 0 && west == 0) flaga = true;
    else {
        cout << "No" << endl;
        return 0;
    }
}
cout << "Yes" << endl;
}
