#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string x;
    cin >> x;
    ll l,ss=0,tt=0;
    l=x.size();

    string s;
    ll ans=0;
    rep(i,l){
        if(x[l-1-i]=='S'){
            ++ss;
        }
        else{
            
            ++tt;
        }
        ans=max(ans,ss-tt);
    }

    cout << 2*ans << endl;
    

    return 0;
}