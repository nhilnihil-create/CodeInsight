#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;

int main(){
    int H,W;
    cin>>H>>W;
    vector<vector<char>>C(H,vector<char>(W));
    rep(i,H){
        rep(j,W){
            cin>>C[i][j];
        }
    }

    rep(i,H){
        rep(k,2){
            rep(j,W){
                cout<<C[i][j];
                }
                cout<<endl;
            }
        }
    return 0;
}