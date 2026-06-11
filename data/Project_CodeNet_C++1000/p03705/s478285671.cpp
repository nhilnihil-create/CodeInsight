#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, a, b;
    cin >> n >> a >> b;

    long long int amax = (n-1) * b + a;
    long long int amin = (n-1) * a + b;
    cout << max(0LL, amax - amin + 1) << endl;
    return 0;
}