#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"yes"<<endl;}else cout<<"no"<<endl;//条件によってYes、Noを出力する
int main(){
    string s;
    cin>>s;
    int n = s.length();
    set<char> se;
    rep(i,n){
        se.insert(s[i]);
    }
    YN(se.size()==n);
}