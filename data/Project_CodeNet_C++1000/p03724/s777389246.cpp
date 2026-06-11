#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define PI 3.14159265358979
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll mod = 1e9+7LL;

int main() {
    ll N, M; cin >> N >> M;
    map<int, int> d;
    rep(i, M){
        ll a, b; cin >> a >> b;
        d[a]++;
        d[b]++;
    }

    bool flag = true;

    rep(i, N){
        if(d.count(i)){
            if(d.at(i)%2!=0) flag = false;
        }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}