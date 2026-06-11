#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x,t;
    cin >> x >> t;
    long long ans;
    ans = (x-t > 0 ? x-t : 0);
    cout << ans << endl;
}