#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using pll = pair<ll,ll>;
const ll INF64 = 1LL << 60;
const int INF = (1 << 29);

int main(){
    int n,m; cin >> n >> m;
    char a[n][n],b[m][m];
    rep(i,n)rep(j,n) cin >> a[i][j];
    rep(i,m)rep(j,m) cin >> b[i][j];

    rep(i,n-m+1){
        rep(j,n-m+1){
            bool flag = true;
            for(int h=i; h<i+m; h++){
                for(int w=j; w<j+m; w++){
                    if(a[h][w]!=b[h-i][w-j]){
                        flag = false;
                        break;
                    }
                }
                if(flag==false) break;
            }

            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}