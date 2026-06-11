#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 550;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        long long a[7];
        long long res = 0;
        for(int i = 0; i < 7; i++){
                cin >> a[i];
        }
        res += a[1];
        for(int i: {0, 3, 4}){
                long long g = min(2ll, a[i]);
                long long shit = (a[i] - g) / 2;
                res += shit * 2;
                a[i] -= shit * 2;
        }
        long long best = 0;
        for(int i = 0; i * 2 <= a[0]; i++){
                for(int j = 0; j * 2 <= a[3]; j++){
                        for(int h = 0; h * 2 <= a[4]; h++){
                                long long cur = (i + j + h) * 2;
                                if((a[0] - i * 2) && (a[3] - j * 2) && (a[4] - h * 2)){
                                        cur += 3;
                                }
                                best = max(best, cur);
                        }
                }
        }

        cout << res + best << "\n";
}
