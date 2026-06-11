#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    string O, E;
    cin >> O >> E;

    rep(i,O.size()){
        cout << O[i];
        if(i+1<=E.size()) cout << E[i];
    }
    cout << endl;
}
