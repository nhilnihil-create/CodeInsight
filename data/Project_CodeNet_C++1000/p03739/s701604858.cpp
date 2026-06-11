#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[n];
    int i;
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long sum = 0;
    long long cnt1 = 0,
              cnt2 = 0;
        for(i = 0; i < n; i++) {
            sum += a[i];
            if (i % 2 == 0) {
                while(sum <= 0) {
                    sum++;
                    cnt1++;
                }
            }
            else {
                while(sum >= 0) {
                    sum--;
                    cnt1++;
                }
            }
        }

        sum = 0;

        for(i = 0; i < n; i++) {
            sum += a[i];
            if (i % 2 == 0) {
                while(sum >= 0) {
                    sum--;
                    cnt2++;
                }
            }
            else {
                while(sum <= 0) {
                    sum++;
                    cnt2++;
                }
            }
        }
    cout << min(cnt1, cnt2) << endl;
}
