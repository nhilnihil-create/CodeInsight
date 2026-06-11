#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main(){
    int n,m;
    cin >> n >> m;
    char A[50][50],B[50][50];
    rep(i,n)rep(j,n) cin >> A[i][j];
    rep(i,m)rep(j,m) cin >> B[i][j];

    bool flag = false;
    rep(y,n)rep(x,n){
        if(y - 1 + m >= n || x - 1 + m >= n) continue;

        flag = true;
        rep(nx,m)rep(ny,m){
            if(A[y+ny][x+nx] != B[ny][nx]) flag = false;
        }

        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}