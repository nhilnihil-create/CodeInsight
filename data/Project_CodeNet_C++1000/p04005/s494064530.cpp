#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll a,b,c;cin>>a>>b>>c;
    if(a%2==0||b%2==0||c%2==0){
        cout<<0<<endl;
        return 0;
    }
    ll res=3e18;
    ll buf=a*b;
    chmin(res,buf);
    buf=a*c;
    chmin(res,buf);
    buf=b*c;
    chmin(res,buf);
    cout<<res<<endl;
}