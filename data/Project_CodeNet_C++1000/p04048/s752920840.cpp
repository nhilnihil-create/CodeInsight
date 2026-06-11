#include <iostream>
using namespace std;
long long solve(long long x, long long n){
    if (x == 0)
        return 0;
    if (x <= n / 2)
        return n + solve(n - 2 * x, n - x);
    else{
        long long cnt = x / (n - x);
        return 2 * cnt * (n - x) + solve(x - cnt * (n - x), n - cnt * (n - x));
    }
}
int main(){
    long long n, x;
    cin >> n >> x;
    cout << x + solve(x, n) << endl;
}
