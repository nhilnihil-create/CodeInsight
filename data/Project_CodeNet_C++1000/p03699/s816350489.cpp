#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        int N;
        cin >> N;
        vector<int> s(N, 0);
        int sum = 0;
        for (int i = 0; i < N; ++i) {
                cin >> s[i];
                sum += s[i];
        }
        sort(s.begin(), s.end());
        for (int i = 0; i < N; ++i) {

                if (sum % 10 == 0) {
                        if (s[i] % 10 != 0) {
                                cout << sum - s[i] << endl;
                                exit(0);
                        }
                }
                else {
                        cout << sum << endl;
                        exit(0);
                }
        }
        cout << 0 << endl;

}
