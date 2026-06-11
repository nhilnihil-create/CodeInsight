#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int getColor(int rate)
{
        if (rate > 0 && rate < 400) {
                return 0;
        }
        else if (rate > 399 && rate < 800) {
                return 1;
        }
        else if (rate > 799 && rate < 1200) {
                return 2;
        }
        else if (rate > 1199 && rate < 1600) return 3;
        else if (rate > 1599 && rate < 2000) return 4;
        else if (rate > 1999 && rate < 2400) return 5;
        else if (rate > 2399 && rate < 2800) return 6;
        else if (rate > 2799 && rate < 3200) return 7;
        else return 8;
}

int main()
{
        int N;
        cin >> N;
        vector<int> L(9, 0);
        for (int i = 0; i < N; ++i) {
                int rate = 0;
                cin >> rate;
                L[getColor(rate)] ++;
        }
        int min = 0;
        int max = 0;
        for (int i = 0; i < 9; ++i) {
                if (L[i] != 0) {
                        if (i == 8) {
                                max += L[i];
                        }
                        else {
                                min++;
                                max++;
                        }
                }
        }
        if (min == 0) min = 1;
        cout << min << " " << max << endl;



}
