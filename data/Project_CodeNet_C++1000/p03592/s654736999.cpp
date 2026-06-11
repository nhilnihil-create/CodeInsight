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
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            int cnt = m * i + n * j - 2 * i * j;
            if(cnt == k){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
	return 0;
}