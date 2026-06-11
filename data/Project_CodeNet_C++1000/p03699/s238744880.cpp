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
vector<int>s(n);
int sum=0;
vector<int> sub;
rep(i,n){
    cin>>s[i];
    sum+=s[i];
    if(s[i]%10!=0){
        sub.pb(s[i]);
    }
}
int l = sub.size();
if(l==0){
    cout<<0<<endl;
}
else if(sum%10!=0){
    cout<<sum<<endl;
}
else{
    sort(sub.begin(),sub.end());
    cout<<sum-sub[0]<<endl;
}
return 0;
}