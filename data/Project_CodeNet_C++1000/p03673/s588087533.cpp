#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    
    list<ll> b;
    bool toggle = true;
    for (auto x : a) {
        toggle ? b.push_back(x) : b.push_front(x);
        toggle ^= true;
    }
    
    if (toggle == false) reverse(b.begin(), b.end());
    for (auto x : b) cout << x << ' ';
    cout << endl;
    
    return 0;
}
