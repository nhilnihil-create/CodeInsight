#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

bool func(int n, int i, vector<ll> &v, vector<ll> &sum) {
    for (int j = i+1; j < n; j++) {
        if (2 * sum[j] < v[j])
            return false;
    }
    return true;
}

int main() {
    int n;  cin >> n;
    vector<ll> sum(n+1, 0);
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        sum[i+1] = sum[i] + v[i];
    int l = -1, r = n-1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (func(n, mid, v, sum))
            r = mid;
        else 
            l = mid;
    }
    

    cout << n - r << endl;
    return 0;
}