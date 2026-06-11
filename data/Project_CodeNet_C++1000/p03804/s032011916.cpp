#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

bool match(vector<vector<char>> a, vector<vector<char>> b, int n){
    bool m = true;
    rep(i,n){
        rep(j,n){
            if(a[i] != b[i]) m = false;
        }
    }
    return m;
}   

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n));
    vector<vector<char>> b(m, vector<char>(m));

    rep(i,n){
        rep(j,n){
            cin >> a[i][j];
        }
    }

    rep(i,m){
        rep(j,m){
            cin >> b[i][j];
        }
    }

    vector<vector<char>> c(m, vector<char>(m));

    rep(i, n-m+1){
        rep(j, n-m+1){

            rep(k,m){
                rep(l,m){
                    c[k][l] = a[i+k][j+l];
                }
            }

            if(match(b,c,m)){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    
    return 0;
}