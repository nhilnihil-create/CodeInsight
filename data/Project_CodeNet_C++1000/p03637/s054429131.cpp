#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll n;
    cin >> n;
    ll cnt_4 = 0;
    ll cnt_2 = 0;
    ll r = n;
    rep(i,n){
        int a;
        cin >> a;
        if(a%4 == 0)cnt_4++;
        if(a%2 == 0)cnt_2++;
    }
    cnt_2 -= cnt_4;
    r -= (cnt_4 + cnt_2);
    if(cnt_2 < 1){
        if(r <= cnt_4 + 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        if(r <= cnt_4) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}