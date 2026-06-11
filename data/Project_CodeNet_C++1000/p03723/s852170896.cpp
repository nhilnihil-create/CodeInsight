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
bool distribute(int& a,int& b,int& c){
    if(a%2==0&&b%2==0&&c%2==0){
        int _a=b/2+c/2;
        int _b=a/2+c/2;
        int _c=a/2+b/2;
        a=_a;
        b=_b;
        c=_c;
        return true;
    }
    else{
        return false;
    }
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int a,b,c;
cin>>a>>b>>c;
int ans=0;
while(distribute(a,b,c)){
    ans++;
    if(a==b&&b==c){
        ans=-1;
        break;
    }
}
cout<<ans<<endl;
return 0;
}