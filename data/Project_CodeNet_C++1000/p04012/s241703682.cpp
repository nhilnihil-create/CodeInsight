#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    string w; cin >> w;
    unordered_map<char,int> cnt;
    for (const auto& i : w) {
        cnt[i]++;
    }
    bool ans = true;
    for (const auto& i : cnt) {
        if (i.second % 2 == 1) ans = false;
    }
    if (ans) printf("Yes");
    else printf("No");
}