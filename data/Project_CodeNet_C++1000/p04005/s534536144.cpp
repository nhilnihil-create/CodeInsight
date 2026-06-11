#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
ll a,b,c;
cin>>a>>b>>c;
ll l1 = max(max(a,b),c);
ll l2 = min(min(a,b),c);
ll l3 = a+b+c-l1-l2;
if(l1%2==0){
    cout<<0<<endl;
}
else{
    ll S1 = ((l1-1)/2)*l2*l3;
    ll S2 = (((l1-1)/2)+1)*l2*l3;
    cout<<abs(S1-S2)<<endl;
} 

return 0;
}