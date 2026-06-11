#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
        }
        bool plus = false;
        long long ans1 = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
                sum += a[i];
                if (plus == false) {
                        if (sum >= 0) {
                                ans1 += (abs(sum)+1);
                                sum = -1;
                        }
                        plus = true;
                }
                else {
                        if (sum <= 0) {
                                ans1 += (abs(sum)+1);
                                sum = 1;
                        }
                        plus = false;
                }
        }
        if (sum == 0) ans1++;

        plus = true;
        long long ans2 = 0;
        sum = 0;
        for (int i = 0; i < n; ++i) {
                sum += a[i];
                if (plus == false) {
                        if (sum >= 0) {
                                ans2 += (abs(sum)+1);
                                sum = -1;
                        }
                        plus = true;
                }
                else {
                        if (sum <= 0) {
                                ans2 += (abs(sum)+1);
                                sum = 1;
                        }
                        plus = false;
                }
        }
        if (sum == 0) ans2++;
        long long ans = (ans1 < ans2) ? ans1 : ans2;
        cout << ans << endl;

}
