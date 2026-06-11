#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll w, a, b; cin >> w >> a >> b;

    if(b > a){
        put(max(0LL, b - a - w));
    }else{
        put(max(0LL, a - b - w));
    }
}