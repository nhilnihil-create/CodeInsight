#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll x,y;cin>>x>>y;
    ll mini=1e18;
    if(x<=y)chmin(mini,y-x);
    if(-x<=y)chmin(mini,y+x+1);
    if(x<=-y)chmin(mini,-y-x+1);
    if(-x<=-y)chmin(mini,-y+x+2);
    cout<<mini<<endl;
}
