#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    int left = 0, right = 0, left_count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[left]) {
            left = i;
            right = i;
            left_count = 1;
        } else if (a[i] > a[right]) {
            right = i;
            mp[a[i] - a[left]]++;
        } else if (a[i] == a[left]) {
            right = i;
            left_count++;
        } else if (a[i] == a[right]) {
            if (left_count > 0) {
                mp[a[i] - a[left]]++;
                left_count--;
            }
        }
    }
    int max_diff = 0, count = 0;
    for (auto p: mp) {
        if (max_diff < p.first) {
            max_diff = p.first;
            count = p.second;
        }
    }
    cout << count << endl;
    return 0;
}
