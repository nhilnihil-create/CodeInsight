#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int H,W; cin>>H>>W;
    vector<vector<char>> image(2*H,vector<char>(W));
    rep(h,0,H)rep(w,0,W){
        char c; cin>>c;
        image.at(2*h).at(w)=image.at(2*h+1).at(w)=c;
    }

    rep(h,0,2*H){
        rep(w,0,W) cout<<image.at(h).at(w);
        cout<<endl;
    }
}