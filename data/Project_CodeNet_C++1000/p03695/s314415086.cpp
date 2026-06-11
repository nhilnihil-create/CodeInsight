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
int a[n];
rep(i,n) cin>>a[i];
//入力
map<int,bool> m;
int count = 0;
int MI=0,MX=0,ans=0;
rep(i,n){
    if(a[i] >=3200) count++;//3200以上の数
    else if(!m[a[i]/400]) ans++;//各色の数 
    m[a[i]/400] =true;//重複避け
}
if(ans==0){
    cout<<1<<" ";
}else
{
    cout<<ans<<" ";
}//3200以上のみだったら1それ以外ならいる色の数が最小

cout<<ans+count<<endl;
    return 0;
}
