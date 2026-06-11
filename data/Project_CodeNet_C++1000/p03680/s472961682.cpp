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
    int n;
    cin>>n;
    int a[n];
    rep(i,n) cin>>a[i];
   
   map<int,bool> m;
   ll count=0;
   int now = 0;
   while(1){
       count++;
       if(m[now]){
           cout<<-1<<endl;
           return 0;
       }else
       m[now] = true;
       now = a[now] - 1;
       if(now == 1){
           cout<<count<<endl;
           return 0;
       }
   }
    
    return 0;
}
