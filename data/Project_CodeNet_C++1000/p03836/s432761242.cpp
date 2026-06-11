#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    string s;
    int x,y;
    x=tx-sx;
    y=ty-sy;
    rep(i,x){
        s=s+'R';
    }

    rep(i,y){
        s=s+'U';
    }

    rep(i,x){
        s=s+'L';
    }

    rep(i,y){
        s=s+'D';
    }

    s=s+'D';

    rep(i,x+1){
        s=s+'R';
    }

    rep(i,y+1){
        s=s+'U';
    }

    s=s+'L';

    s=s+'U';

    rep(i,x+1){
        s=s+'L';
    }

    rep(i,y+1){
        s=s+'D';
    }

    s=s+'R';











    cout << s << endl;

    
    

    return 0;
}