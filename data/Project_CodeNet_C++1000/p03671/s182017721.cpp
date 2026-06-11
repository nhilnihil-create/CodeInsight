#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int answer = a + b;
    int result = a + c;
    int legit = b + c;
    if (answer <= result && answer <= legit) {
        cout << answer;
        return 0;
    }
    if (result <= answer && result <= legit) {
        cout << result;
        return 0;
    }
    if (legit <= result && legit <= answer) {
        cout << legit;
        return 0;
    }
}