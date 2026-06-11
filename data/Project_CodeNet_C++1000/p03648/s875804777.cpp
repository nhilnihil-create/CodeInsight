#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
    ll K;
    cin >> K;
    if(!K){
        cout << "4\n3 3 3 3\n";
        return 0;
    }else if(K == 1){
        cout << "3\n1 0 3\n";
        return 0;
    }
    ll size = min<ll>(K, 50);
    ll a[size];
    ll kaisu = K / size;
    for(ll i = 0; i < size; i++) a[i] = size + kaisu - 1;
    for(ll i = 0; i < K % size; i++) a[i] += 1;
    if(K % size){
        for(ll i = K % size; i < size; i++) a[i] -= K % size;
    }
    cout << size << endl;
    for(ll i = 0; i < size; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}