#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    int res=s.size()+t.size();
    rep(i,s.size()){
        bool ok=true;
        if(s.size()-i>t.size())continue;
        for(int j=0;j<s.size()-i;j++){
            if(s[i+j]!=t[j]){
                ok=false;
                break;
            }
        }
        if(ok){
            int buf=t.size()+i;
            chmin(res,buf);
        }
    }
    cout<<res<<endl;
}