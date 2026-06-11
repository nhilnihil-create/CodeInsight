#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ll N, K; cin >> N >> K;
    vector<P> p;
    rep(i, N){
        int a, b; cin >> a >> b;
        p.push_back(make_pair(a, b));
    }
    sort(p.begin(), p.end());

    ll now = 0;
    for (auto f : p){
        int x = f.first;
        int y = f.second;
        now += y;
        if(now >= K){
            cout << x << endl;
            break;
        }
    }

    return 0;
}