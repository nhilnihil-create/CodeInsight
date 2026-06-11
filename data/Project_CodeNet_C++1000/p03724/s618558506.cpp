#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,m;
    cin >> n >> m;
    ll a,b;
    vector <int> k(n);
    rep(i,m){
        cin >> a >> b;
        ++k[a-1];
        ++k[b-1];


    }

    rep(i,n){
        if(k[i]%2==1){
            cout << "NO" << endl;
            break;
        }
        if(i==(n-1)){
            cout << "YES" << endl;
        }

    }
    

    return 0;
}