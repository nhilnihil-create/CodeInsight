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
    int64_t h,w;
    cin>>h>>w;
    if(h%3==0 || w%3==0){
        cout<<0<<endl;
        return 0;
    }
    //3で割れない場合
    int Min = min(h,w);
    //そのまんま横or縦に切った場合
    int64_t s = h*w;
    for(int i=1;i<h;i++){
        int64_t sa;
        if(w%2==0){
            sa=abs(w*i-(w/2)*(h-i));
        }
        else{
            int64_t a,b,c;
            a = w*i;
            b = (w/2)*(h-i);
            c = (w/2+1)*(h-i);
            sa = max(a,max(b,c)) - min(a,min(b,c));
        }
        if(sa<Min){
            Min = sa;
        }
    }
    for(int i=1;i<=w;i++){
        int64_t sa;
        if(h%2==0){
            sa=abs(h*i - (h/2)*(w-i));
        }
        else{
            int64_t a,b,c;
            a = h*i;
            b = (h/2)*(w-i);
            c = (h/2+1)*(w-i);
            sa = max(a,max(b,c))-min(a,min(b,c));
        }
        if(sa<Min){
            Min = sa;
        }
    }
    cout<<Min<<endl;
}