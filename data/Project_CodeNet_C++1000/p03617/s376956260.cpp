#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll q,h,s,d;cin>>q>>h>>s>>d;
    ll n;cin>>n;
    ll one=min(q*4,min(h*2,s));
    if(one*2<d){
        ll res=one*n;
        cout<<res<<endl;
    }else{
        ll res=(n/2)*d+one*(n%2);
        cout<<res<<endl;
    }
}