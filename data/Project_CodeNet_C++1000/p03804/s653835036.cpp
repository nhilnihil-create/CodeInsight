#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n));
    for (ll i = 0;i < n;i++){
        for (ll j = 0;j < n;j++){
            cin >> a[i][j];
        }
    }
    vector<vector<char>> b(m, vector<char>(m));
    for (ll i = 0;i < m;i++){
        for (ll j = 0;j < m;j++){
            cin >> b[i][j];
        }
    }

    bool ans = false;
    bool t = true;

    for (ll x = 0; x <= n-m; x++){
        for (ll y = 0; y <= n-m; y++){
            for (ll i = 0; i < m; i++){
                for (ll j = 0; j < m; j++){
                    if (a[i+x][j+y] != b[i][j]){
                        t = false;
                        goto out1;
                    }
                }
            }
            out1:
            if (t){
                ans = true;
                goto out2;
            }
            t = true;
        }
    }
    out2:

    YesNo(ans);
}