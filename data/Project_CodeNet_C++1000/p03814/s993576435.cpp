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
int main(){
    string s;
    cin>>s;
    int n=s.length();
    int ap,zp;
    bool a = false;
    rep(i,n){
        if(s[i]=='A' && !a){
            ap = i;
            a = true;
        }
        if(a && s[i]=='Z'){
            zp = i;
            //break;
        }
    }
    cout<<zp-ap+1<<endl;
}