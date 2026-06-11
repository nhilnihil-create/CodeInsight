#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    stack<int> s;
    long long result = 0, count[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (!s.empty() && a[s.top()] > a[i]) {
            s.pop();
        }
        if (s.empty()) {
            count[i] = i + 1;
        } else {
            count[i] = i - s.top();
        }
        s.emplace(i);
    }
    while (!s.empty()) {
        s.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] > a[i]) {
            s.pop();
        }
        if (s.empty()) {
            count[i] = (n - i) * count[i];
        } else {
            count[i] = (s.top() - i) * (count[i]);
        }
        result += a[i] * count[i];
        s.emplace(i);
    }
    cout << result;
    return 0;
}