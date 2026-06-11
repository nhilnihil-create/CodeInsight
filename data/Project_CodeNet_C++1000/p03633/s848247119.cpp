#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
    return a / GCD(a, b) * b;
}


int main(void){
    long long n;
    cin >> n;
    
    vector<long long> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    
    long long ans = t[0];
    
    for (int i = 0; i < n; i++) ans = LCM(ans,t[i]);
    
    cout << ans << endl;
}
