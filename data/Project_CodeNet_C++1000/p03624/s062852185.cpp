#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
//エラトステネスの篩による素数列挙 O(NloglogN)
int main(){
    string s;
    cin>>s;
    map<char,int> charmap;
    int n=s.length();
    rep(i,n){
        charmap[s[i]]++;
    }
    for(char c='a';c<='z';c++){
        if(charmap[c]==0){
            cout<<c<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
}