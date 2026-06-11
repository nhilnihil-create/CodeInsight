#include <bits/stdc++.h>
using namespace std;

using ll = long long int;


int main(){
    ll n, L;
    cin >> n >> L;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int idx = -1;
    for(int i=0;i<n-1;i++){
        if(a[i]+a[i+1] >= L){
            idx = i;
            break;
        }
    }
    if(idx != -1){
        cout << "Possible" << endl;
        for(int i=0;i<idx;i++){
            cout << i+1 << endl;
        }
        for(int i=n-2;i>=idx;i--){
            cout << i+1 << endl;
        }
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
}
