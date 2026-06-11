#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;
using pll = pair<ll,ll>;

int main(){
    ll N,W;
    cin >> N >> W;
    vector<vector<ll> > object(4);
    ll w0 = 0;
    rep(i,N){
        int a,b;
        cin >> a >> b;
        if(i==0)w0=a;
        object[a-w0].push_back(b);
    }
    rep(i,4){
        sort(All(object[i]));
        reverse(All(object[i]));
    }
    vector<vector<ll> > sum(4);
    rep(i,4){
        int s = object[i].size()+1;
        sum[i].resize(s);
        rep(j,s-1){
            sum[i][j+1]=sum[i][j]+object[i][j];
        }
    }
    ll res = 0;
    for(int i=0;i<sum[0].size();i++){
        for(int j=0;j<sum[1].size();j++){
            for(int k=0;k<sum[2].size();k++){
                for(int l=0;l<sum[3].size();l++){
                    ll v = sum[0][i]+sum[1][j]+sum[2][k]+sum[3][l];
                    ll w = w0*i+(w0+1)*j+(w0+2)*k+(w0+3)*l;
                    if(w<=W)res = max(res,v);
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}