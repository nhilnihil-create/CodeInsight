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
    int n,m;
    cin>>n>>m;
    map<int,int> p;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        p[a]++;
        p[b]++;
    }
    rep(i,n){
        cout<<p[i]<<endl;
    }
}