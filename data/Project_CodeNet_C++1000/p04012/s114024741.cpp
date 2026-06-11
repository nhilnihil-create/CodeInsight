#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    string w;
    cin >> w;
    int n = w.size();

    map<char, int> a;
    rep(i, n) {
        a[w[i]]++;
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (a[w[i]] % 2) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}