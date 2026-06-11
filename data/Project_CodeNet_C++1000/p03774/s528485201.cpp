#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換
int keta(ll n){int ans=0;while(n>0){n /= 10; ans++;}return ans;}
ll _pow(ll a,ll b){ll ans = 1;rep(i,b){ ans *= a;}return ans;}

int main() {
int n,m;cin>>n>>m;
ll a[n],b[n],c[m],d[m];
rep(i,n){
    cin>>a[i]>>b[i];
}
rep(i,m){
    cin>>c[i]>>d[i];
}
rep(i,n){
    int ans = 0;
    int M = INF;
    rep(j,m){
        int D = abs(a[i]-c[j])+abs(b[i]-d[j]);
        if(D<M){
            ans = j+1;
            M=D;
        }
    }
    cout<<ans<<endl;
}

    return 0;
}
