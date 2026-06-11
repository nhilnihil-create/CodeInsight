#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
   int H,W;
   cin>>H>>W;
   vector<vector<char>> A(H, vector<char>(W));
   vector<vector<char>> ans(2*H, vector<char>(W));
    rep(i,H){
        rep(j,W){
            cin>>A[i][j];
            ans[i*2][j]=A[i][j];
            ans[i*2+1][j]=A[i][j];
        
        }
    }
    rep(i,2*H){
        rep(j,W){
            cout<<ans[i][j];
        }
      cout<<""<<endl;
    }
}
