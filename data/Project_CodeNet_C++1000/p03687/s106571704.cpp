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
string s;
cin>>s;
int n=s.size();
int res=MAX;
for(char c:s){
    int l=0;
    while(s[l]!=c)l++;
    int tmp=l;
    reps(i,n,l){
        if(s[l]!=c)continue;
        int j=i+1;
        while(j<n&&s[j]!=c)j++;
        tmp=max(tmp,j-i-1);
        i=j-1;
    }
    res=min(res,tmp);
}

cout<<res<<endl;
return 0;
}