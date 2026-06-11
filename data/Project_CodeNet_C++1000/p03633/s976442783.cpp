#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long ,long b){
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b){
    return (a / gcd(a,b) ) * b;
}

int main(void){
    int n;
    cin >> n;
    
    vector<long long> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    
    long long ans = t[0];
    for (int i = 0; i < n; i++) ans = lcm(ans,t[i]);
    cout << ans << endl;
}
