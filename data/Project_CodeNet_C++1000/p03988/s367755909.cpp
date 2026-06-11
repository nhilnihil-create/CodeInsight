//
// Created by yjq on 2019/11/7.
//
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i <= b; i++)
const int N = 100+100;
using namespace std;

int a[N],n,maxx,minn,sum[N];

int main(){
    scanf("%d",&n);
    maxx = 0, minn = n+1;
    rep(i,1,n) scanf("%d",&a[i]), maxx = max(maxx,a[i]), minn = min(minn,a[i]), sum[a[i]]++;
    int tp = (maxx+1)/2;
    if(minn < tp) printf("Impossible\n");
    else{
        int jud = 1;
        if(maxx%2 == 0 && sum[tp] != 1) jud = 0;
        if(maxx%2 == 1 && sum[tp] != 2) jud = 0;
        if(maxx == 1 && n != 2) jud = 0;
        rep(i,tp+1,maxx){
            if(sum[i] < 2) jud = 0;
        }
        if(jud) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
