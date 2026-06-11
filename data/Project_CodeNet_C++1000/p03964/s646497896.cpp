#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int N;
    cin >> N;
    ll x = 1, y = 1;
    for (int i = 0; i < N; i++) {
        int T, A;
        cin >> T >> A;
        if (x % T != 0) x += T - (x % T);
        if (y % A != 0) y += A - (y % A);
        if (x/T*A > y) y = x/T*A;
        else x = y/A*T;
    }
    cout << x+y << endl;
    return 0;
}