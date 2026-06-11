#include <stdio.h>
#include <string>
#include <cmath>
#include <list>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    int length = s.length();

    int p[11];

    long long ans = 0;

    for (int i = 0; i < pow(2, s.length() - 1); i++) {
        for (int j = 0; j < s.length() - 1; j++) {
            p[j] = i & (int) pow(2, j);
        }
        long long sum = 0;
        long long tmp = stoll(s.substr(0, 1));
        for (int j = 0; j < s.length() - 1; j++) {
            if (p[j] == 0) {
                tmp = tmp * 10 + stoll(s.substr(j + 1, 1));
            } else {
                sum += tmp;
                tmp = stoll(s.substr(j + 1, 1));
            }
        }
        sum += tmp;
        ans += sum;
        // cout << ans << endl;
    }

    cout << ans;
}
