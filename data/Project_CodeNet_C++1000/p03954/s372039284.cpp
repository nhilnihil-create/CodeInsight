#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, a[N << 1];

int sma (int i, int j, int k) {
    return a[i] <= k && a[j] <= k;
}

int big (int i, int j, int k) {
    return a[i] > k && a[j] > k;
} 

int check (int k) {
    for (int i = 0; i < n - 1; ++i) {//枚举距离判断
        if (big (n + i, n + i + 1, k) || big (n - i, n - i - 1, k)) return 0;
        if (sma (n + i, n + i + 1, k) || sma (n - i, n - i - 1, k)) return 1;
    }
    return sma (1, 1, k);//没有重合的特判
}

int main(){
	cin >> n;
    for (int i = 1; i <= (n << 1) - 1; ++i) {
        cin >> a[i];
    }
    int l = 1, r = 2 * n - 1, ans;
    while (l < r) {//二分判断
        int mid = (l + r) >> 1;
        if (check (mid)) {
            r = mid;
        } else {
			l = mid + 1;
		}
	}
    cout << r;
    return 0; 
}
