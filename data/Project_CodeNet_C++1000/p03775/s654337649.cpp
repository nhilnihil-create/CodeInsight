#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    int a = 1;
    for (int i=1; i<=sqrt(n); i++) {
        if (n % i == 0) a = max(a, i);
    }
    
    int b = n / a;
    int ans = 0;
    int x = max(a, b);
    while(x > 0) {
        ans++;
        x/=10;
        }
   cout << ans << endl; 
    
}