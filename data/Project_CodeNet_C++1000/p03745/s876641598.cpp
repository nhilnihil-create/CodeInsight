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
int n;
cin>>n;
vector<int>a(n);
rep(i,n)cin>>a[i];
int mode=-1;
int ans = 1;
int before = a[0];
reps(i,n,1){
    int val=a[i]-before;
    if(val==0) continue;

    if(val>0){
        if(mode==-1){
            mode=0;
        }
        else if(mode!=0){
            ans++;
            mode=-1;
        }
    }
    else{
        if(mode==-1){
            mode=1;
        }
        else if(mode!=1){
            ans++;
            mode=-1;
        }
    }
    before=a[i];
}
cout<<ans<<endl;
return 0;
}
