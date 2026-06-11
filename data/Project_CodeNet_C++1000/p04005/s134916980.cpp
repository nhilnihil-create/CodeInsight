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
ll a[3];
rep(i,3){
    cin>>a[i];
}
sort(a,a+3);

ll g = a[1] * a[0];
if(a[2] % 2 == 0){
    cout<<0<<endl;
}else
{
    cout<<g<<endl;
}

   return 0;
}
