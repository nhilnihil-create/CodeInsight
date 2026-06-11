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
    ll n;
    cin >> n;
    ll a[n];
    ll check[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        check[i] = 0;
    }
    sort(a, a+n);
    ll count = 0;
    for(ll i = 0; i < n; i++){
        check[count]++;
        if(a[i] != a[i+1])
            count++;
    }
    sort(check, check+count);
    ll ans = 0;
    ll b = 0;
    while(b < count-1){
        if(check[b] > 1){
            check[b]--; check[b+1]--;
            ans+=2;
        }
        else
            b++;
    }
    if(check[count-1]%2 == 1)
        ans+=(check[count-1]-1);
    else
        ans+=check[count-1];
    
    cout << n-ans << endl;
    return 0;
}