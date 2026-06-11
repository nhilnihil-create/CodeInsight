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
int h,w;
cin>>h>>w;
char a[h+2][w+2];
rep(i,w+2){
    a[0][i] = '#';
    a[h+1][i] = '#';
}
rep(i,h+2){
    a[i][0] = '#';
    a[i][w+1] = '#';
}
for(int i = 1; i < h+1 ; i++){
    for(int j = 1; j < w+1; j++){
        cin>>a[i][j];
    }
}

rep(i,h+2){
    rep(j,w+2){
        cout<<a[i][j];
    }
    cout<<endl;
}
   return 0;
}
