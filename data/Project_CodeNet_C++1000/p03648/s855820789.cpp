#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

lint ans[55];

int main(){
    lint K; cin >> K;

    for(int i=2;i<=50;i++){
        lint x = (K+i-1) / i;
        lint bt = (i+1) * (x-1) + i - K;
        lint up = (i+1) * x + i - K;
        if(up<=bt || (lint)1e16+1001<up) continue;
        for(int j=0;j<i-1;j++) {ans[j] = (i+1) * x + i - K - 1;}
        lint x2 = K - (i-1) * x;
        ans[i-1] = (i+1) * x2 + i - K - 1;
        for(int j=0;j<i;j++) if(ans[j-1]<0) continue;
        cout << i << endl;
        for(int j=0;j<i;j++) cout << ans[j] << ' ';
        cout << endl;
        return 0;
    }
}
