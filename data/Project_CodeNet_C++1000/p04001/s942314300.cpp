#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P = pair<int,int>;

ll dfs(int i, ll sum, string s){
    // ベースケース
    if(i >= s.length()) return sum;
    // 再起ステップ
    // +を代入しない
    ll sum1 = dfs(i+1, 0, s);
    // +を代入する
    if(i+1 < s.length()) s = s.insert(i+1, "+");
    // 加算
    string tmp;
    int c=0;
    ll sum2=0;
    while(c < s.length()){
        if(s.substr(c, 1) == "+"){
            // +なら加算処理
            sum2+=atoll(tmp.c_str());
            // 加算後は再度数字を連結するのでクリア
            tmp.clear();
        }else{
            // 数字なら文字列を連結
            tmp += s[c];
        }
        c++;
    };
    
    // 最後の数字を加算
    if(tmp.length()>0) sum2+=atoll(tmp.c_str());
    sum2 = dfs(i+2, sum2, s);
        
    return sum1+sum2;
}

int main(int argc, const char * argv[]) {
    string s;
    
    cin >> s;
    
    ll sum = dfs(0, 0, s);

    cout << sum << endl;
    
    return 0;
}
