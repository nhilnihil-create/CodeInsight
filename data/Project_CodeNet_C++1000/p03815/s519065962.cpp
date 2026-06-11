#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t x, ans=0;
    cin >> x;
    ans += x/11*2;
    x %= 11;
    if(7<=x) ans += 2; 
    else if(1<=x && x<=6) ans++; 
    cout << ans << endl;
}