#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;
const int MAX = 5e5 + 10;

int main(){
    int n; cin >> n;
    ll a = 0, b = 0;
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        if(i == 0){
            a = x; 
            b = y;
            continue;
        }
        ll cnt = max((a + x - 1) / x, (b + y - 1) / y);
        if(cnt * x >= a && cnt * y >= b){
            a = cnt * x;
            b = cnt * y;
        }
    }
    cout << a + b << endl;
}