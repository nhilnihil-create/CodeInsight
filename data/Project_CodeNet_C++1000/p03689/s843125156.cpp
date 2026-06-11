#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;
int H,W,h,w;
int ans[500][500];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>H>>W>>h>>w;
    if(H%h==0&&W%w==0){
        cout <<"No"<<"\n";
        return 0;
    }
    else if(H%h==0){
        rep(i,0,H){
            rep(j,0,W){
                if(i%h==0&&j%w==0) ans[i][j]=1000;
                if(i%h==0&&j%w==W%w) ans[i][j]=-1001;
            }
        }
    }
    else if(W%w==0){
        rep(i,0,H){
            rep(j,0,W){
                if(i%h==0&&j%w==0) ans[i][j]=1000;
                if(j%w==0&&i%h==H%h) ans[i][j]=-1001;
            }
        }
    }
    else{
        rep(i,0,H){
            rep(j,0,W){
                if(i%h==0&&j%w==0) ans[i][j]=1000;
                if(i%h==0&&j%w==W%w) ans[i][j]=1000;
                if(j%w==0&&i%h==H%h) ans[i][j]=1000;
                if(j%w==W%w&&i%h==H%h) ans[i][j]=-3001;
            }
        }
    }
    cout <<"Yes"<<"\n";
    rep(i,0,H){
        rep(j,0,W){
            if(j==W-1) cout <<ans[i][j]<<"\n";
            else cout <<ans[i][j]<<" ";
        }
    }
}