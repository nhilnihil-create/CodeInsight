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
ll a,b;
cin>>a>>b;
if((a<0&&b>0)||(a==0||b==0)){
    cout<<"Zero"<<endl;
}
else if(a>0&&b>0){
    cout<<"Positive"<<endl;
}else
{
    ll count = - a - b + 1;
    if(count % 2 == 0){
         cout<<"Positive"<<endl;
    }else
    {
        cout<<"Negative"<<endl;
    }
    
}


    return 0;
}
