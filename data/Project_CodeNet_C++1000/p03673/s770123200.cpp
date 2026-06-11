#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    deque<ll> b;
    for(ll i = 0; i < n; i++){
        if(i%2 == 0) b.push_back(a[i]);
        else b.push_front(a[i]);
    }
    if(n%2 == 0){
        for(int i = 0; i < n; i++){
            cout << b[i] << ' ';
        }
        cout << endl;
    }
    else{
        for(int i = n - 1; i >= 0; i--){
            cout << b[i] << ' ';
        }
        cout << endl;
    }
}