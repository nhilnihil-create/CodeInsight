#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define ll long long

int main(void){
    ll n, a, b;
    cin >> n >> a >> b;
    ll x[n];
    for(ll i = 0; i < n; i++)   
        cin >> x[i];
    ll ans = 0;
    for(ll i = 0; i < n-1; i++){
        if((x[i+1]-x[i])*a > b)
            ans += b;
        else
            ans+=(x[i+1]-x[i])*a;
    }
    cout << ans << endl;
    return 0;
}