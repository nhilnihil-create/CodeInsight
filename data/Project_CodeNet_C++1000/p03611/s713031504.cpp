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
   //input
   map<int ,int> m;
   rep(i,n){
       m[a[i]-1]++;
       m[a[i]]++;
       m[a[i]+1]++;
   }//1つの数字で3つの数に慣れる可能性があるため全部数える
   int ans = 0;
   for(auto i: m){
       ans = max(ans,i.second);
   } //max number
   cout<<ans<<endl;
    return 0;
}
