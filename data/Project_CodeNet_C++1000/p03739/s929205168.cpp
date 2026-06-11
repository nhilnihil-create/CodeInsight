#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[100010];
    long long sum1 = 0;
    long long sum2 = 0;
    long long res1 = 0;
    long long res2 = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i]; 
        sum1 += a[i];
        if (i % 2 == 0){
            if (sum1 < 0) continue;
            else if (sum1 >= 0) {
                res1 += sum1 + 1;
                sum1 = -1;
            }
        }
        else if (i % 2 == 1){
            if (sum1 > 0) continue;
            else if (sum1 <= 0) {
                res1 += -sum1 + 1;
                sum1 = 1;
            }
        }
    }
    for (int i=1; i<=n; i++){
        sum2 += a[i];
        if (i % 2 == 0){
            if (sum2 > 0) continue;
            else if (sum2 <= 0) {
                res2 += -sum2 + 1;
                sum2 = 1;
            }
        }
        else if (i % 2 == 1){
            if (sum2 < 0) continue;
            else if (sum2 >= 0) {
                res2 += sum2 + 1;
                sum2 = -1;
            }
        }
    }
    long long ans = min(res1, res2);
    cout << ans << endl;
    return 0;
}