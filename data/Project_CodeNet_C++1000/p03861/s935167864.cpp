#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)1
using ll = long long;

int main(){
    ll a,b,x; cin >> a >> b >> x;
    ll r = b/x;
    ll l;
    if(a==0){
        l = -1;
    }else{
        l = (a-1)/x;
    }

    cout << r - l << endl;
}