#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    ll price[4];
    rep(i,4){
        cin >> price[i];
    }
    price[0] *= 4;  price[1] *= 2;
    
    ll price_1L(min({price[0],price[1],price[2]}));

    ll n;   cin >> n;

    if(price_1L*2<=price[3]){
        cout << n*price_1L << endl;
    }else if(n%2==0){
        cout << n/2*price[3] << endl;
    }else{
        cout << n/2*price[3]+price_1L << endl;
    }


    return 0;
}