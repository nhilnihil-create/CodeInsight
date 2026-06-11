#include<iostream>
using namespace std;

int main() {
    int A, B, C; cin >> A >> B >> C;
    int arr[B - 1];
    string ans = "NO";
    for (int i = 1; i <= B; i++) {
        int num = i * A % B;
        if (num == C) {
            ans = "YES";
        }
    }
    cout << ans << endl;
}
