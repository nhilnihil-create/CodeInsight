#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
#define coa cout << ans << endl; return 0;
using namespace std;
using ll = long long;
template<typename T>
using vec = vector<T>;
template<typename T>
using vvec = vector<vector<T>>;
using qint = queue<int>;
using sint = stack<int>;
using pii = pair<int, int>;


int main(){
    int n, m;
    cin >> n >> m;
    vvec<int> street(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        street[a].push_back(b);
        street[b].push_back(a);
    }

    for(auto city : street){
        cout << city.size() << endl;
    }

    return 0;
}
