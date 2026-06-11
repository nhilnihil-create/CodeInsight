#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int  long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
using namespace std;
/// age ye mosh dp ro baze dashti dp tedad baz shodeye baste nashode yadet nare !!
/// joooob zadam
const int N=2e5+100;
ll nxt[N][26];
ll par[N];
ll dp[N];
int32_t main(){
    string s;
    cin >> s;
    ll n=s.size();

    for (int i=0;i<26;i++){
        ll t=n+1;
        for (int j=n;j>0;j--){
            nxt[j][i]=t;
            if (s[j-1]-'a'==i){
                t=j;
            }
        }
        nxt[0][i]=t;
    }
    memset(dp,69,sizeof dp);
    dp[n+1]=0;
    for (int i=n;i>-1;i--){
        for (int j=0;j<26;j++){
            ll z=nxt[i][j];
            dp[i]=min(dp[i],dp[z]+1);

          //  cout << i << " " << z << " " << dp[i] << " " << dp[z] << endl;
        }
        for (int j=0;j<26;j++){
            ll z=nxt[i][j];
            if (dp[z]+1==dp[i]){
                par[i]=j;
                break;
            }
        }
    }
    string a="";
    ll x=0;
    while(x!=n+1){
        ll v=par[x];
        a+='a'+v;
        x=nxt[x][v];
    }
    cout << a << endl;
   // /cout << dp[0];

}
