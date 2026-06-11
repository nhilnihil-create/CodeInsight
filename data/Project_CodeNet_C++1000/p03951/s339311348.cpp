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
string s,t;
cin>>n>>s>>t;
int b=n;
rep(i,n){
    if(s[i]==t[0]){
        bool ok=true;
        int k=0;
        reps(j,n,i){
            if(s[j]!=t[k]){
                ok=false;
                break;
            }
            k++;
        }
        if(ok){
            b=i;
            break;
        }
    }
}
string st=s.substr(0,b)+t;
cout<<st.size()<<endl;
return 0;
}