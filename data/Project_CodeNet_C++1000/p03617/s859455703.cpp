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
ll a[3],D;
ll n;
cin>>a[0]; a[0] *= 4;
cin>>a[1]; a[1] *= 2;
cin>>a[2];
cin>>D;
cin>>n;
sort(a,a+3);
if(a[0] <= D/2){
cout<<n*a[0];
}else{
    if(n%2 == 0){
        cout<<n*D/2<<endl;
    }else
    {
        cout<<(n/2)*D + a[0]<<endl;
    }
    
}


   return 0;
}
