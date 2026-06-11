#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;

    vector <vector <char> > a(n,vector <char>(n));
    vector <vector <char> > b(m,vector <char>(m));
    rep(i,n){
        string s;
        cin >> s;
        rep(j,n){
            a[i][j] = s[j];
        }
    }
    rep(i,m){
        string s;
        cin >> s;
        rep(j,m){
            b[i][j] = s[j];
        }
    }

    bool ans = false;

    for(int i=0; i<=n-m ; i++){     //スタート位置
        for(int j=0; j<=n-m; j++){
            bool ok = true;
            for(int k=0; k<=m-1; k++){
                for(int l=0; l<=m-1; l++){
                    if(a[i+k][j+l] != b[k][l]){
                        ok = false;
                        break;
                    }
                }
                if(!ok){
                    break;
                }
            }

            if(ok) ans = true;
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}