#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll SIZE = 1e5 + 10;

vector<vector<ll>> vec;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    fastInp;

    string s;
    cin >> s;
    ll cnt[4];
    for (int i = 0; i < 4; i++) cnt[i] = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'E') cnt[0]++;
        if (s[i] == 'W') cnt[1]++;
        if (s[i] == 'S') cnt[2]++;
        if (s[i] == 'N') cnt[3]++;
    }

    if (((cnt[0] != 0) ^ (0 != cnt[1])) || (((cnt[2] != 0) ^ ( 0 != cnt[3])) > 0)) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
    return 0;
}