#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() { 
    ll a, b;
    cin >> a >> b;
    if(a > 0 && b > 0) cout << "Positive" << endl;
    else if(a * b <= 0) cout << "Zero" << endl;
    else {
        if(abs(a + b) % 2 == 0) cout << "Negative" << endl;
        else cout << "Positive" << endl;
    }
    return 0;
}