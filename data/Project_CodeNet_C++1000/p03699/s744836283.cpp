#include<iostream>
using namespace std;

int main() {
    int n, s[110];
    int sum = 0, mini = 1000;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        sum += s[i];
        if (s[i] % 10 != 0) mini = min(mini, s[i]);
    }

    if (sum % 10 == 0) {
        if (mini == 1000) cout << 0 << endl;
        else cout << sum - mini << endl;
    }
    else  cout << sum << endl;
}