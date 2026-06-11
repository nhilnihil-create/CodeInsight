#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int W, H, N;
    vector<int> x(N);
    vector<int> y(N);
    vector<int> a(N);

    cin >> W >> H >> N;
    REP(i,N){
        cin >> x[i] >> y[i] >> a[i];
    }

    LL w_l = 0;
    LL w_r = W;
    LL h_d = 0;
    LL h_u = H;

    REP(i,N){
        if(a[i]==1){
            if(w_l < x[i]){
                w_l = x[i];
            }
        }else if(a[i]==2){
            if(w_r > x[i]){
                w_r = x[i];
            }
        }else if(a[i]==3){
            if(h_d < y[i]){
                h_d = y[i];
            }
        }else{
            if(h_u > y[i]){
                h_u = y[i];
            }
        }
    }

    LL w = w_r - w_l;
    LL h = h_u - h_d;

    if(w < 0 || h < 0){
        cout << 0 << endl;
    }else{
        cout << w*h << endl;
    }
    return 0;
    

}