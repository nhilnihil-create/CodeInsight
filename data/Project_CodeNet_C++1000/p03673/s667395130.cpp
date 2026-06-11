#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> x(n);
    for (ll i = 0;i < n;i++){
        cin >> x[i];
    }
    deque<ll> a;
    deque<ll> b;
    for (ll i = 0; i < n; i++){
        if (i%2 == 0){
            a.push_back(x[i]);
        }
        else{
            b.push_back(x[i]);
        }
    }

    if (n%2 == 0){
        reverse(b.begin(),b.end());
        for (ll i = 0; i < b.size(); i++){
            cout << b[i] << " ";
        }
        for (ll i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
    }
    else{
        reverse(a.begin(),a.end());
        for (ll i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        for (ll i = 0; i < b.size(); i++){
            cout << b[i] << " ";
        }
    }

    cout << endl;

}