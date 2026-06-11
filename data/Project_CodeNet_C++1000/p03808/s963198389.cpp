#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        sum += A[i];
    }
    ll addPerCycle = (N*(N+1))/2;
    // cerr << "addPerCycle=" << addPerCycle  <<"sum=" << sum<< endl;
    if(sum%addPerCycle != 0){
        cout <<"NO" << endl;
        return 0;
    }
    ll div = sum/addPerCycle;
    vector<ll> diffA(N);
    for(int i=0;i<N;i++){
        diffA[i] = A[i] -A[(N+i-1)%N];
    }
    ll xSum = 0; 
    for(int i=0;i<N-1;i++){
        ll temp = (div-diffA[i])/N;
        if((div -diffA[i])%N != 0 || temp <0 || temp>div){
            // cerr <<"temp=" <<temp << endl;
            cout <<"NO" << endl;
            return 0;
        }
        xSum += temp;
    }

    // cerr <<"xSum = " << xSum << endl;

    if(div-(div-xSum) *N == diffA[N-1]){
        cout <<"YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    

    return 0;
}