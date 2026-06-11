#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
        int n;
        cin >> n;
        vector<ll> wa;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
                ll now;
                cin >> now;
                if (now != 0) {
                        sum += now;
                } else {
                        wa.push_back(sum);
                        sum = 0;
                }
        }
        if (sum > 0) wa.push_back(sum);

        ll result = 0;
        for (auto x : wa) {
                result += x / 2;
        }
        cout << result << endl;
}
