#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    rep(i,h) rep(j,w) cin>>a[i][j];

    rep(i,w+2) cout<<'#';
    cout<<"\n";
    rep(i,h){
        cout<<'#';
        rep(j,w) cout<<a[i][j];
        cout<<'#'<<"\n";
    }
    rep(i,w+2) cout<<'#';
    return 0;
}