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
    int n,p; cin>>n>>p;
    int a[n];
    rep(i,n) cin>>a[i];
    map<int,int> m;
    rep(i,n){
        m[a[i]%2]++;
    }
    if(p == 1 && m[1] == 0 ){
        cout<<0<<endl;
        return 0;
    }
    if(p == 0 && m[0] == n){
        cout<<setprecision(18)<<pow(2,n)<<endl;
        return 0;
    }
    
    cout<<setprecision(18)<<pow(2,n)/2<<endl;
    
    return 0;
}
