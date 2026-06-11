#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MAX = 10000000000;

int main(){
    ll n; cin >> n;
    
    ll sum = 0;
    ll i;
    
    for(i = 0 ; i < MAX ; i ++){
        sum += i;
        if(sum >= n) break;
    }
    
    cout << i -- << endl;
    
}
