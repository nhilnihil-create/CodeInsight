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
string a,b;
cin>>a>>b;
int A = a.size(),B = b.size();
if(A < B){
    cout<<"LESS"<<endl;
}else if(A > B){
    cout<<"GREATER"<<endl;
}else
{
    rep(i,A){
        if(a[i] < b[i]){
            cout<<"LESS"<<endl;
            return 0;
        }else if(a[i] > b[i]){
             cout<<"GREATER"<<endl;
             return 0;
        }
    }
    cout<<"EQUAL"<<endl;
}

   return 0;
}
