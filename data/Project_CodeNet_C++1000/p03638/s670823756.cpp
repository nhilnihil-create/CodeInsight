#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007

int main(){
    int h,w;
    cin >> h>>w;
    vector< vector <int>> d(h, vector<int>(w,0));
    int n;
    cin>>n;
    vector<int64_t> a(n);
    rep(i,n){
        cin>>a[i];
    }
    bool up=false,down=true;
    int t=0,y=0;
    int color=0;
    while(d[0][w-1]==0||d[h-1][w-1]==0){
        while(a[color]>=1){
        d[t][y] =  color+1;
        //cout << "d["<<t<<"]["<<y<<"]="<<d[t][y]<< endl;
        a[color] --;
        if(t==h-1&&down){//下まで行った
            down=false;
            up=true;
            y++;
            continue;
        }
        else if(t==0 && y!=0&&up){//上まで行った
            down=true;
            up=false;
            y++;
            continue;
        }
        if(down){
            t++;
        }
        if(up){
            t--;
        }
        }
        //全部塗り切った
        color++; 
    }
    rep(i,h){
        rep(j,w){
            cout <<d[i][j]<<" ";
        }
        cout <<endl;
    }

}