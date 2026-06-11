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
    string s,t;
    cin>>s>>t;
    int n=s.length();
    rep(i,n-1){
        cout<<s[i]<<t[i];
    }
    if(t.length()==n){
        cout<<s[n-1]<<t[n-1]<<endl;
    }
    else{
        cout<<s[n-1]<<endl;
    }
}