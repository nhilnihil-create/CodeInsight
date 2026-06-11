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
string s;
cin>>s;
map<char,bool> m;
rep(i,s.size()){
    m[s[i]] = true;;
}
if(m['S'] ^ m['N'] == false && m['E'] ^ m['W'] == false){
    cout<<"Yes"<<endl;
}else
{
    cout<<"No"<<endl;
}

   return 0;
}
