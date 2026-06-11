#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    deque<ll>b;
    if(n%2==0){
        for(ll i=0;i<n;i++){
            if(i%2==0){
                b.push_back(a[i]);
            }
            else {
                b.push_front(a[i]);
            }
        }
    }
    else {
        for(ll i=0;i<n;i++){
            if(i%2==1){
                b.push_back(a[i]);
            }
            else {
                b.push_front(a[i]);
            }
        }
    }
    for(ll i=0;i<n;i++){
        cout << b[i] << " ";
    }
    cout << endl;
}