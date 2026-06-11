#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

long long n, m;
int mod = 1e9 + 7;

int main() {
    cin >> n >> m;
    long long sumX = 0, sumY = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sumX += (2 * i - n + 1) * x;
        sumX %= mod;
    }
    
    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        sumY += (2 * i - m + 1) * y;
        sumY %= mod;
    }
    
    cout << sumX * sumY % mod << endl;
}