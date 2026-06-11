#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,p;cin>>n>>p;
    ll o=0,e=0;
    rep(i,n){
        int a;cin>>a;
        a%=2;
        if(a==0)e++;
        else o++;
    }
    
    ll res=1;
    rep(i,n)res*=2;
    if(o==0){
        if(p==0)cout<<res<<endl;
        else cout<<0<<endl;
        return 0;
    }
    cout<<res/2<<endl;
}