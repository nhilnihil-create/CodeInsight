#include<iostream>

using namespace std;

int main(void) {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 1)cnt++;
    }
    cout << (cnt % 2 == 0 ? "YES" : "NO") << endl;
}