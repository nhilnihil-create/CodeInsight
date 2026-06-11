#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int x = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'I') {
            x++;
            ans = max(ans, x);
        } else {
            x--;
        }
    }
    cout << ans << endl;
}
