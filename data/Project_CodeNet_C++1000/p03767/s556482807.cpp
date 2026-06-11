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

int main() {
int n;
cin>>n; n *= 3;
ll a[n]; 
rep(i,n){
   cin>>a[i]; 
}
sort(a,a+n);
ll ans = 0;
for(int i = n/3; i < n; i += 2){
ans += a[i];
}
cout<<ans<<endl;
return 0;
}
