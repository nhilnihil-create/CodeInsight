#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    int H,W;cin>>H>>W;
    char C[H][W];
    char A[2*H][W];
    rep(i,H){
        rep(j,W){
            cin>>C[i][j];
            A[2*i][j]=C[i][j];
            A[2*i+1][j]=C[i][j];
        }
    }
    rep(i,2*H){
        rep(j,W){
            cout<<A[i][j];
        }
    cout<<endl;
    }
    return 0;
}