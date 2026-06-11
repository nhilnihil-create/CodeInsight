#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int mod = 1e9 + 7;

int main(){

    int n, m;
    cin >> n >> m;

    long long xSum = 0;
    long long xSum2 = 0;
    long long before = 0;
    cin >> before;
    for(int i = 1; i < n; i++){
        long long temp;
        cin >> temp;
        long long len = temp - before;
        xSum2 = (xSum2 + (i * len));
        xSum = (xSum + xSum2) % mod;
        before = temp;
    }

    long long ySum = 0;
    long long ySum2 = 0;

    cin >> before;
    for(int i = 1; i < m; i++){
        long long temp;
        cin >> temp;
        long long len = temp - before;
        ySum2 = (ySum2 + (i * len));
        ySum = (ySum + ySum2) % mod;
        before = temp;
    }

    long long ans = (xSum * ySum) % mod;

    cout << ans << endl;

    return 0;
}