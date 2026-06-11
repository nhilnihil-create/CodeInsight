#include<bits/stdc++.h>
using namespace std;

long long f(long long x, long long y) {
    if (x > y)  swap(x, y);
    if (y%x == 0)       return 2*y-x;
    return 2*(y/x)*x + f(x, y%x);
}

int main() {
    long long n, x;
    cin>>n>>x;

    cout<<n+f(n-x, x)<<endl;
}
