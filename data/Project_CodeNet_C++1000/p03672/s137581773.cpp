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
string s; cin>>s;
s.pop_back();
while(1){
    //cout<<s<<endl;
    if(s.size() % 2 == 1){
        s.pop_back();//一文字へらす
        continue;
    }//奇数列はない
    bool flag = true;
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size()/2 + i]){
            flag = false;//前と真ん中から見て違ったらだめ
        }
    }
    if(flag){
    cout<<s.size()<<endl;//上が通れば大丈夫
    return 0;
    }else
    {
        s.pop_back();
    }
}
    return 0;
}
