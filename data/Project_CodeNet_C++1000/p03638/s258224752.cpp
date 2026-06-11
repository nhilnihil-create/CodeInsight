#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(void){
    int h, w, n;
    cin>>h>>w>>n;
    vector<int> v(n);
    int nowi=0;
    rep(i, n) cin>>v[i];
    vector<int> s(h*w);
    rep(i, n){
        rep(j, v[i]) s[nowi+j]=i+1;
        nowi+=v[i];
    }
    vector<vector<int> > ans(h, vector<int>(w));
    rep(i, h){
        if(i%2==0){
            rep(j, w) ans[i][j]=s[i*w+j];
        }
        else {
            rep(j, w) ans[i][w-1-j]=s[i*w+j];
        }
    }
    rep(i, h){
        rep(j, w) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}