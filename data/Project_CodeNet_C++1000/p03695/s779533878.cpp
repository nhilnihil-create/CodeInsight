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
int calc_color(int rate){
    int color;
    if(rate<400){
        color=0;
    }
    else if(rate<800){
        color=1;
    }
    else if(rate<1200){
        color=2;
    }
    else if(rate<1600){
        color=3;
    }
    else if(rate<2000){
        color=4;
    }
    else if(rate<2400){
        color=5;
    }
    else if(rate<2800){
        color=6;
    }
    else if(rate<3200){
        color=7;
    }
    else{
        color=8;
    }
    return color;
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n;
cin>>n;
int a;
map<int,int> rate;
rep(i,n){
    cin>>a;
    rate[calc_color(a)]++;
}
int ans=0;
int god=0;
for(auto v:rate){
    if(v.first==8){
        god+=v.second;
    }
    else{
        ans++;
    }
}
int o=god>0 ?1:0;
cout<<max(ans,o)<<" "<<ans+god<<endl;
return 0;
}