#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int main() {
    int N;
    cin >> N;
    ll ret = 0;
    vector<int> a;
    rep(i, N) {
        ret += (i+1);
        a.push_back(i+1);
        if (ret >= N) break;
    }
    ll tmp = ret - N;
    rep(i, a.size()) {
        if (a[i] != tmp) {
            cout << a[i] << endl;
        }
    }
    return 0;
}
