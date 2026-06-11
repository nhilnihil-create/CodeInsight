#include<iostream>
using namespace std;
#define ll long long
int main() {
    ll n, sum = 0, time;
    cin >> n;
    ll a[n], diff[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if(i) diff[i - 1] = a[i] - a[i - 1];
    }
    diff[n - 1] = a[0] - a[n - 1];
    if(sum % (n * (n + 1) / 2)){
        cout << "NO" << endl;
        return 0;
    }
    time = sum / (n * (n + 1) / 2);
    for(ll i = 0; i < n; i++){
        if(diff[i] > time || (time - diff[i]) % n) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
