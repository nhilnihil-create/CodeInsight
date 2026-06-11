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
int q,h,s,d,n;
cin>>q>>h>>s>>d>>n;
ll res=0;
while(n>0){
    if(2<=n){
        ll min_cost=min(min(8*q,4*h),min(2*s,d));
        res+=min_cost*(n/2);
        n%=2;
    }
    else{
        ll min_cost=min(min(4*q,2*h),s);
        res+=min_cost*n;
        n%=1;
    }
}
cout<<res<<endl;
return 0;
}