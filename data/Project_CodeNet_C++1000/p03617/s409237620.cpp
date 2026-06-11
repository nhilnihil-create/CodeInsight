#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll q,h,s,d,n;cin>>q>>h>>s>>d>>n;
    ll b=min(s,min(q*4,h*2));
    if(b*2>d){
        ll res=n/2*d+(n%2)*b;
        cout<<res<<endl;
    }else{
        cout<<n*b<<endl;
    }
}