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
int n; cin>>n;
ll c,k; cin>>c>>k;
ll t[n];
rep(i,n){
    cin>>t[i];
}
sort(t,t+n);
ll count = 0,ans = 1,time = t[0] + k;
rep(i,n){
    if(time >= t[i]){
        count++;
    }else{
        ans++;
        count = 0;
        time = t[i] + k;
    }
    if(count == c){
        ans++;
        count = 0;
        time = t[i] + k;
    }

//cout<<"time=="<<time<<" t[i]=="<<t[i]<<" count=="<<count<<endl;
}
if(c == 1) ans--;

cout<<ans<<endl;
    return 0;
}
