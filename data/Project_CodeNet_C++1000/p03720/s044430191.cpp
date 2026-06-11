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
vv(int) G(51);
int n,m;
cin>>n>>m;
rep(i,m){
    int a,b;
    cin>>a>>b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
}

rep(i,n){
    cout<<G[i].size()<<endl;

}


   return 0;
}
