#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll a, b;
    cin >> a >> b;
    if (a >= 1) cout << "Positive" << endl;
    else if (b <= -1) cout << ((b-a)%2==0 ? "Negative" : "Positive") << endl;
    else cout << "Zero" << endl;
    return 0;
}