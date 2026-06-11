// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
// g++ hoge.cpp -std=c++17 -I . でコンパイルできる
// -fsanitize=undefinedでオーバーフロー検出
#include <bits/stdc++.h>
//#include <atcoder/all>
#define mod 1000000007
#define INF LLONG_MAX
#define ll int
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
//using namespace atcoder;
typedef pair<ll,ll> P;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};


int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,k,x,y,maxi=0,f=0,sum=0;
    string str2,str1;
    int hoge=0;
    cin>>n>>m;
    string s1[n];
    string s2[m];
    rep(i,n) cin>>s1[i];
    rep(i,m) cin>>s2[i];
    for(ll i=0;i<=n-m;i++){
        for(ll j=0;j<=n-m;j++){
            f=0;
            for(ll k=0;k<m;k++){
                for(ll l=0;l<m;l++){
                    if(s1[i+k][j+l]!=s2[k][l])f=1;
                }
            }
            if(!f){
                Yes;
                return 0;
            }
        }
    }
No;


    return 0;
}
