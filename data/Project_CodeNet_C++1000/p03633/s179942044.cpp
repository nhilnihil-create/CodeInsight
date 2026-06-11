#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    if (a % b == 0 || b % a == 0) return min(a, b);
    if (a < b) swap(a, b);
    if (a == 1 || b == 1) return 1;
    else return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}
int main() {
    long long n, l = 1;
    cin >> n;
    long long t[n];
    for (long long i = 0; i < n; i++) 
    {
        cin >> t[i];
        l = lcm(l, t[i]);
    }
    cout << l;
}