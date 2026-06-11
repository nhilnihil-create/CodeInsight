#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;

#define int long long

int my(int n, string s) {
    int ans = 1;
    map<char, int> cnt;
    for (auto t : s) {
        cnt[t]++;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        for (char z = c + 1; z <= 'z'; z++) {
            ans += cnt[c] * cnt[z];
        }
    }
    return ans;
}

int stupid(int n, string s) {
    set<string> hv;
    hv.insert(s);
    for (int i = 0; i < n; i++) {
        for (int len = 1; i + len <= n; len++) {
            string t = s;
            reverse(t.begin() + i, t.begin() + i + len);
            hv.insert(t);
        }
    }
    return (int)hv.size();
}

void read() {
    string s;
    cin >> s;
    int n = (int)s.size();
    cout << my(n, s) << endl;
}

void run(int n) {
    string s(n, '$');
    for (auto &t : s) {
        t = rand() % 3 + 'a';
    }
    if (stupid(n, s) != my(n, s)) {
        cout << "wa " << s << endl;
        exit(0);
    } else {
        cout << "ok " << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         if (s[i] != s[j]) ans++;
    //     }
    // }

    read();

    // int n;
    // cin >> n;
    // while (true) run(n);
}   
