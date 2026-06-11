#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define rep(i, n) for(int (i) = 0; i < (n); i++)

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int main(){
    int n;
    cin >> n;
    ll out;
    cin >> out;
    for(int i = 1; i < n; i++){
        ll a;
        cin >> a;
        out = lcm(out, a);
    }
    cout << out << endl;
}