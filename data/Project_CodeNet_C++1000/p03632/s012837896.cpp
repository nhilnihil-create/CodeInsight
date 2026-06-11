#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<bool> A(101,false),B(101,false);
    for(int i=a;i<=b;i++){
        A[i]=true;
    }
    for(int i=c;i<=d;i++){
        B[i]=true;
    }
    int t=0;
    rep(i,101){
        if(A[i]&&B[i]){
            t++;
        }
    }
    if(t>0){
        t--;
    }
    cout<<t<<endl;
}