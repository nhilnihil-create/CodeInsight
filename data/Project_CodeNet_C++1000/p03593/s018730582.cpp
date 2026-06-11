#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll h,w ; cin >> h >> w;
    vector<ll> cnt(26,0);
    rep(i,h){
        string a; cin >> a;
        rep(j,w){
            ll x = a.at(j) - 'a';
            cnt.at(x)++;
        }
    }

    bool ok = true;
    ll cnt2 = 0 , cnt4 = 0;
    ll cnt2lim,cnt4lim;
    if(h%2 && w%2){
        cnt2lim = (h-1)/2 + (w-1)/2;
        cnt4lim = (h-1)*(w-1)/4;
    }else if(h%2){
        cnt2lim = w/2;
        cnt4lim = (h-1)*w/4;
    }else if(w%2){
        cnt2lim = h/2;
        cnt4lim = (w-1)*h/4;
    }else{
        cnt4lim = h*w/4;
        cnt2lim = 0;
    }

    rep(i,26){
        while(cnt.at(i)>=4){
            if(cnt4==cnt4lim) break;
            cnt.at(i)-=4;
            cnt4++;
            if(cnt4==cnt4lim) break;
        }           
        if(cnt4==cnt4lim) break; 
    }
    rep(i,26){
        while(cnt.at(i)>=2){
            if(cnt2==cnt2lim) break;
            cnt.at(i)-=2;
            cnt2++;
            if(cnt2==cnt2lim) break;
        }           
        if(cnt2==cnt2lim) break; 
    }
    if(cnt2!=cnt2lim || cnt4!=cnt4lim){
        ok = false;
    }

    if(ok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}