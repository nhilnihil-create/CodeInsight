#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ll N;
    cin >> N;
    vector<ll> a(N*3);
    for(int i = 0; i < N*3 ; i++){
        cin >> a[i];
    }
    
    sort(a.begin(),a.end(),greater<ll>());
    ll sum = 0;
    for(int i = 1; i < N*2 ; i+=2){
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}