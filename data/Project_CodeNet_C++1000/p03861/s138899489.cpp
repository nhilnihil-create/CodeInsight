#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ll a,b;
    cin >> a >> b;
    ll x;
    cin >> x;
    a--;
    if(b == 0) cout << 1 << endl;
    else if(a == -1) cout << b/x+1 << endl;
    else cout << b/x-a/x << endl;
    return 0;
}