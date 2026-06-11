#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int w,h,n;cin >> w >> h >> n;
    vector<int> u(w),v(h);
    rep(i,0,n){
        int x,y,a;cin >> x >> y >> a;
        x--,y--;
        if(a==1){
            rep(j,0,x+1){
                u[j]=true;
            }
        }
        if(a==2){
            rep(j,x+1,w){
                u[j]=true;
            }
        }
        if(a==3){
            rep(j,0,y+1){
                v[j]=true;
            }
        }
        if(a==4){
            rep(j,y+1,h){
                v[j]=true;
            }
        }
    }
    int ans=0;
    rep(i,0,w){
        rep(j,0,h){
            if(!u[i]&&!v[j]){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
