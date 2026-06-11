#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll N, K, a, b;
    cin >> N >> K;
    vector<P> ab;
    rep(i,N) {
        cin >> a >> b;
        ab.push_back(make_pair(a, b));
    }
    sort(ab.begin(), ab.end());
    ll sum = 0;
    rep(i,N) {
        sum += ab.at(i).second;
        if (sum >= K) {
            cout << ab.at(i).first << endl;
            return 0;
        }
    }
}
