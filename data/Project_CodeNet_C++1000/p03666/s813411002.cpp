#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    long long int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    long long int diff = b - a;
    long long int low = 0, high = n - 1;
    while (low < high) {
        long long int mid = (low + high) / 2;
        long long int n1 = (c + d) * mid - n * d + d;
        long long int n2 = (c + d) * mid - n * c + c;
        if (n1 <= diff && diff <= n2) {
            cout << "YES" << endl;
            return 0;
        }
        if (n1 > diff) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if ((c + d) * low - n * d + d <= diff && (c + d) * low - n * c + c >= diff) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
