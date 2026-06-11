#include <bits/stdc++.h>
using namespace std;

int main()
{

        int N;
        int T;
        cin >> N >> T;
        vector<int> t(N);
        for (int i = 0; i < N; ++i) {
                cin >> t[i];
        }
        long long start = -1;
        long long end = 0;
        long long ans = 0;

        for (int i = 0; i < N; ++i) {

                if (start == -1) {
                        start = t[i];
                        end = t[i] + T;
                        ans += (end - start);
                }
                else {

                        if (t[i] <= end) {
                                ans += (t[i] + T - end);
                                end = t[i] + T;
                        }
                        else {
                                start = t[i];
                                end = t[i] + T;
                                ans += (end - start);
                        }
                }
        }
        cout << ans << endl;
}
