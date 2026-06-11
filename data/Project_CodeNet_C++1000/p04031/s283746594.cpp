#include<iostream>
#include<string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int lli;

const int INF = 100100100;

int main()
{
    // Input numbers
    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    int minimum = *std::min_element(a.begin(), a.end());
    int max = *std::max_element(a.begin(), a.end());

    lli ans = INF;

    for (int i = minimum; i < max+1; ++i) {
        lli tmp = 0;
        for (int j = 0; j < (int)a.size(); ++j) {
            tmp += (a[j] - i) * (a[j] - i);
        }

        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}