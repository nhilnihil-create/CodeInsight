#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int x, y;
    cin >> x >> y;

    vec<int> g = {0,1,3,1,2,1,2,1,1,2,1,2,1};
    if(g[x] == g[y]){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
