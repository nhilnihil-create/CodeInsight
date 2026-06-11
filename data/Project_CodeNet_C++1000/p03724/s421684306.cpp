#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,M;
    cin >> N >>M;
    vector<ll> X(N);
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >>b;
        --a;--b;
        if(a!=0){
            X[a]++;
        }
        if(b!=0){
            X[b]++;
        }
    }
    for(int i=0;i<N;i++){
        if(X[i]%2!=0){
            cout <<"NO" << endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

    return 0;
}