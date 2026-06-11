#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> dist(n, 0);
    int max_a = 0;
    rep(i,n){
        int a;
        cin >> a;
        ++dist[a];
        chmax(max_a, a);
    }
    bool ok = true;
    if(max_a%2 == 0){
        for(int i = 1; i < max_a/2; ++i) ok &= (dist[i] == 0);
        ok &= (dist[max_a/2] == 1);
        for(int i = max_a/2+1; i <= max_a; ++i) ok &= (dist[i] >= 2);
    }
    else{
        for(int i = 1; i < (max_a + 1)/2; ++i) ok &= (dist[i] == 0);
        ok &= (dist[(max_a + 1)/2] == 2);
        for(int i = (max_a + 1)/2 + 1; i <= max_a; ++i) ok &= (dist[i] >= 2);
    }
    if(ok) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}
