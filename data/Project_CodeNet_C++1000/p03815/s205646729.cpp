#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL solve(LL x) {
    if(x == 0) return 0;
    if(x < 7) return 1;
    if(x < 12) return 2;
    LL y = x/11;
    return y*2+solve(x-11*y);
}

int main() {
    LL x;
    cin >> x;
    cout << solve(x) << endl;
    return 0; 
}