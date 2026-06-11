#include<bits/stdc++.h>
using namespace std;
#define rep(i,m,n) for(int i=m;i<(int)n;i++)
int main(){
    int h,w;
    cin>>h>>w;
    char a[h+2][w+2];
    rep(i,0,w+2){
        a[0][i]='#';
        a[h+1][i]='#';
    }
    rep(i,0,h+2){
        a[i][0]='#';
        a[i][w+1]='#';
    }
    rep(i,1,h+1){
        rep(j,1,w+1){
            cin>>a[i][j];
        }
        cout<<endl;
    }
    rep(i,0,h+2){
        rep(j,0,w+2){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}