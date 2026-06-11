#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

ll arr[300005];
bool decreasing (ll a, ll b){
    if (a > b)
        return true;
    else
        return false;
}
int main()
{
    ll n;
    cin >> n;
    ll g = 3*n;
    
    for (ll i = 1; i<= g; i++){
        cin >> arr[i];
    }
    
    sort(arr+1, arr+g+1, decreasing);
    int cntr = 0;
    ll total = 0;
    for (ll i = 1; i<= g; i++){
        if (cntr == n)
            break;
        
        if (i%2==0){
            cntr++;
            total = total + arr[i];
        }
    }
    cout << total << endl;
    return 0;
}
