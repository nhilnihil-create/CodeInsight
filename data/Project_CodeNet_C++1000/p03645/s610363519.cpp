#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, M;
    cin >> N >> M;
    unordered_map<int,bool> mp1;
    unordered_map<int,bool> mp2;
    
    rep(i,M){
        int a,b;
        cin >> a >> b;
        --a,--b;
        if(a==0) mp1[b]=true;
        if(b==(N-1)) mp2[a]=true;
    }
    
    bool ans = false;
    
    rep(i,N){
        if(mp1[N-1] || mp1[i] && mp2[i]){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;    
}
