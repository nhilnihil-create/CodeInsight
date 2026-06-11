#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int w,h,n;cin>>w>>h>>n;
    vector<vector<int>> t(h,vector<int>(w,0));
    rep(i,n){
        int x,y,a;cin>>x>>y>>a;x--;y--;
        switch(a){
            case 1:
                rep(j,h)rep(k,x+1)t[j][k]++;
                break;
            case 2:
                rep(j,h)for(int k=x+1;k<w;k++)t[j][k]++;
                break;
            case 3:
                rep(j,y+1)rep(k,w)t[j][k]++;
                break;
            case 4:
                for(int j=y+1;j<h;j++)rep(k,w)t[j][k]++;
                break;
        }
    }
    int res=0;
    rep(i,h)rep(j,w)if(t[i][j]==0)res++;
    cout<<res<<endl;
}
