#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    ll a=n,b=1;
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0){
            a=i;b=n/i;
        }
    }
    string A=to_string(a),B=to_string(b);
    int An=A.size(),Bn=B.size();
    int res=max(An,Bn);
    cout<<res<<endl;
}