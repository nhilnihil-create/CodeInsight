#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = long long int;

int main() {
    i64 n, a, b;
    cin >> n >> a >> b;
    vector<i64> h(n);
    i64 m = 0;
    for(int i = 0; i < n; ++i){
        cin >> h[i];
        m = max(m, h[i]);
    }
    i64 left = 0, right = m / b + 1;
    while (right - left > 1) {
        i64 mid = left + (right - left) / 2;
        i64 cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (h[i] - mid * b > 0) {
                i64 tmp = h[i] - mid * b;
                i64 d = a - b;
                cnt += (tmp + d - 1) / d; 
            }
        }
        if(cnt <= mid) right = mid;
        else left = mid;
    }
    cout << right << endl;
}