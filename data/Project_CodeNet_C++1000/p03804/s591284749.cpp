#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,m;cin>>n>>m;
    char a[n][n],b[m][m];
    rep(i,n)rep(j,n) cin>>a[i][j];
    rep(i,m)rep(j,m) cin>>b[i][j];
    rep(i,n-m+1)rep(j,n-m+1){
        bool ok=true;
        rep(k,m)rep(l,m){
            if(a[i+k][j+l]!=b[k][l]){
                ok=false;
                break;
            }
        }
        if(ok){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}