#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

double kaijyo(int n){
    int k(1);
    for(int i=n;i>0;i--){
        k *= i;
    }

    return k;
}

double distance(int x[],int y[],int i,int j){
    int dx = (x[i] - x[j]) * (x[i] - x[j]);
    int dy = (y[i] - y[j]) * (y[i] - y[j]);
    return sqrt(dx+dy);
}

int main(){
    ll a,b,c;
    cin >> a >> b >> c;

    ll less_side(min({a*b,b*c,c*a}));


    ll another_side(0);
    if(less_side==a*b){
        another_side = c;
    }else if(less_side==b*c){
        another_side = a;
    }else{
        another_side = b;
    }

    if(another_side%2==0){
        cout << 0 << endl;
    }else{
        cout << less_side << endl;
    }

    return 0;
}