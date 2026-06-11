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
int n; cin>>n;
int a[n]; rep(i,n) cin>>a[i];
int count = 0;
rep(i,n){
    if(a[a[i]-1] == i+1) count++;
}

cout<<count / 2<<endl;
   return 0;
}
