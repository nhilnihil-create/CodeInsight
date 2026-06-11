#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (a%b == 0) return(b);
    else return (gcd(b,a%b));
}

long long lcm (long long a, long long b) {
    long long g = gcd(a,b);
    return a / g * b;
}

int main(void){
    int n;
    cin >> n;
    
    long long ans = 1;
    for(int i = 0; i < n; i++) {
        long long t;
        cin >> t;
        ans = lcm(ans,t);
    }
    cout << ans << endl;
}
