#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

ll INF (1ll << 60);

using namespace std;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main(){
    int n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    int upper = 1 << n;
    ll ans = INF;
    for(int bit = 0; bit < upper; bit++) {
        int index = 0;
        unordered_set<int> us;
        int b = bit;
        while(b != 0) {
            if(b & 1) {
                us.insert(index);
            }
            index++;
            b >>= 1;
        }
        if(us.size() != k) {
            continue;
        }
        if(us.find(0) == us.end())
            continue;
        ll tmp = 0;
        vector<ll> aa= a;
        ll tmpmax = a[0];
        for(int i = 1; i < n; i++) {
            if(us.find(i) != us.end()) {
                if(a[i] <= tmpmax) {
                    aa[i]= tmpmax + 1;
                    tmp += aa[i] - a[i];
                }
                tmpmax = aa[i];
            } else {
                if(a[i] > tmpmax) {
                    tmp = INF;
                    break;
                }
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
