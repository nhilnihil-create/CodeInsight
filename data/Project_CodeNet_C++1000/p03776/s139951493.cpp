#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r) {
    if (r > n) {
        return 0;
    }
    if (r > n / 2) {
        r = n - r;
    }
    if (r == 0) {
        return 1;
    }
    long long choose = n;
    for (int i = 2; i <= r; i++) {
        choose *= n - i + 1;
        choose /= i;
    }
    return choose;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), greater<long long>());
    
    map<int,int> freq;
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }
    
    long double mean = 0;
    long long amt = 0, prev = -1;
    for (int i = 0; i < a; i++) {
        mean += nums[i];
        if (nums[i] != prev) {
            prev = nums[i];
            amt = 1;
        }
        else {
            amt++;
        }
    }
    mean /= a;

    long long ways = 0;
    if (prev == nums[0]) {
        for (int i = a; i <= b; i++) {
            ways += nCr(freq[prev], i);
        }
    }
    else {
        ways = nCr(freq[prev], amt);
    }
    
    printf("%.20Lf\n%lld", mean, ways);
    return 0;
}