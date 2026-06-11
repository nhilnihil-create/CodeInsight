#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    ll a, b, x;
    cin >> a >> b >> x;

    ll st = a / x;
    ll end = b / x;

    if (a % x == 0) cout << end - st + 1 << endl;
    else cout << end - st << endl;

}