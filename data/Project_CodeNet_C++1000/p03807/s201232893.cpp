#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int flag = 1;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (a % 2) flag = 1 - flag;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}