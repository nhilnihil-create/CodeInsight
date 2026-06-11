#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int h,w;
    cin>>h>>w;
    vector<string> a(h);
    rep(i,h){
        cin >>a[i];
    }
    rep(i,w+2) putchar('#');
    putchar('\n');
    rep(i,h){
        putchar('#');
        rep(j,w) cout << a[i][j];
        putchar('#');
        putchar('\n');
    }
    rep(i,w+2) putchar('#');
    putchar('\n');

}