#include <iostream>
using namespace std;
long long const mod = 1e9+7;
int main(void){
    int n, m;
    long long X = 0, Y = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        X += (x + mod) * (2*i - n + 1 + mod);
        X %= mod;
    }
    for(int i=0;i<m;i++){
        long long y;
        cin >> y;
        Y += (y + mod) * (2*i - m + 1 + mod);
        Y %= mod;
    }
    cout << (X * Y) % mod << endl;
}
