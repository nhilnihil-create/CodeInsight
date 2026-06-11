#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,m;
    cin>>n>>m;
    char fi1[n][n];
    char fi2[m][m];

    rep(i,n){
        rep(j,n){
            cin>>fi1[i][j];
        }
    }

    rep(i,m){
        rep(j,m){
            cin>>fi2[i][j];
        }
    }

    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            bool ok=true;
            rep(k,m){
                rep(l,m){
                    if(fi1[i+k][j+l]!=fi2[k][l]) ok=false;
                }
            }
            if(ok){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout<<"No"<<endl;
}
