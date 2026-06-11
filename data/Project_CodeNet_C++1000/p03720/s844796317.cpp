#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, M;
    cin >> N >> M;
    
    map<int,int> mp;
    rep(i, M) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        ++mp[a];
        ++mp[b];
    }        
    rep(i,N){
        cout << mp[i] << endl;
    }
}
