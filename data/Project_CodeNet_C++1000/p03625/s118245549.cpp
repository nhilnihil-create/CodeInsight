#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    map<int, int> m;
    rep(i, N){
        int a; cin >> a;
        m[a]++;
    }

    ll ans1 = 0;
    ll ans2 = 0;
    for(auto p : m){
        auto key = p.first;
        auto value = p.second;

        if(value >= 4){
            ans2 = key;
            ans1 = key;
        } else if (value >= 2){
            ans1 = ans2;
            ans2 = key;
        }
    }

    cout << ans1*ans2 << endl;

    return 0;
}