#include<bits/stdc++.h>

using namespace std;
const int mx = 1000007;
int repeatfactor[mx];
const long long mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int m = i;
        for (int j = 2; j * j <= m ; j++) {
            while(m % j == 0) {
                repeatfactor[j]++;
                m = m / j;
            }
        }
        repeatfactor[m]++;
    }

    long long divisor = 1;

    for(int i = 2; i <= n; i++) {
        if(repeatfactor[i]== 0)
            continue;

        divisor = divisor * (repeatfactor[i] + 1);
        divisor = divisor % mod;
    }
    cout << divisor << endl;
}
