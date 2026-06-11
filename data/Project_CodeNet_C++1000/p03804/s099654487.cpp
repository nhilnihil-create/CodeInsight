#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m; cin >> n >> m;
    vector<string> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    for(int i = 0; i <= n - m; ++i){
        for(int j = 0; j <= n - m; ++j){
            bool match = true;
            for(int k = 0; k <= m - 1; ++k){
                for(int l = 0; l <= m - 1; ++l){
                    if(a[k+i][l+j] != b[k][l]) match = false;
                }
            }
            if(match){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}