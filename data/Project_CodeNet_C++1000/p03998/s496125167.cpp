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
    string sa,sb,sc;
    cin>>sa>>sb>>sc;
    int turn = 0;
    int na,nb,nc;
    na = sa.length();
    nb = sb.length();
    nc = sc.length();
    int ta=0,tb=0,tc=0;
    while(1){
        
        
       
        if(turn==0){
            if(ta==na){cout<<'A'<<endl;return 0;}
            turn = sa[ta]-'a';
            ta++;
        }
        else if(turn==1){
            if(tb==nb){cout<<'B'<<endl;return 0;}
            turn = sb[tb]-'a';
            tb++;
        }
        else{
            if(tc==nc){cout<<'C'<<endl;return 0;}
            turn = sc[tc]-'a';
            tc++;
        }
    }
}