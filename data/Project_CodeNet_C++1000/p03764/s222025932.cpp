#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const long long MOD = (long long)1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> x(n), y(m);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < m; i++){
        cin >> y[i];
    }
    long long a = 0, b = 0;
    for(int i = 1; i < n; i++){
        a += i * x[i] - (n - i) * x[i - 1];
        while(a < 0) a += MOD;
        a %= MOD;
    }
    for(int i = 1; i < m; i++){
        b += i * y[i] - (m - i) * y[i - 1];
        while(b < 0) b += MOD;
        b %= MOD;
    }
    cout << (a * b) % MOD << endl;
    return 0;
}
