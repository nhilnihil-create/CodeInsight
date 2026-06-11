#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    long long n; cin >> n;
    long long minx = 100000000;
    long long k = 1;
    while (k * k <= n){
        if (n%k == 0){
            long long x = max(to_string(n/k).size(), to_string(k).size());
            minx = min(x, minx);
        }
        k ++;
    }
    cout << minx << endl;
}