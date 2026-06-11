#include <iostream>
#include <vector>
using namespace std;
long long mod = 1e9+7;
long long f(int n, vector<int> x){
    long long res = 0;
    for(int i=0;i<n;i++){
        res += (mod + i*2-n+1) % mod * (mod + x[i]) % mod;
        res %= mod;
    }
    return res;
}
int main(void){
    int n, m;
    cin >> n >> m;
    vector<int> x(n, 0), y(m, 0);
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<m;i++) cin >> y[i];
    cout << f(n, x) * f(m, y) % mod << endl;
}
