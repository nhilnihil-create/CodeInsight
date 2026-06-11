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
    if(s==t){
        cout<<n<<endl;
        return 0;
    }
    int tmp=0;
    rep(i,n){
        if(s[i]==t[tmp])tmp++;
        //else tmp=0;
    }
    int res=2*n-tmp;
    cout<<res<<endl;
}