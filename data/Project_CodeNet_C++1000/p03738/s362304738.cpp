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
    string a,b;
    cin>>a>>b;
    if(a.length()<b.length()){
        cout<<"LESS"<<endl;
    }
    else if(a.length()>b.length()){
        cout<<"GREATER"<<endl;
    }
    else{
        int n=a.length();
        bool eq = true;
        rep(i,n){
            if(a[i]!=b[i]){
                eq = false;
                if(a[i]<b[i])cout<<"LESS"<<endl;
                else cout<<"GREATER"<<endl;
                break;
            }
        }
        if(eq){
            cout<<"EQUAL"<<endl;
        }
    }
}