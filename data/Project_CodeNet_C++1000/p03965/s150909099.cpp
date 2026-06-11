#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e10;

int main() {
    string s; cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        if (s.at(i) == 'p') cnt ++;
    }
    cout << n/2 - cnt << endl;
}

