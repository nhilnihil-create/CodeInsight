#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; // 組数
    int people = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int L;  // 左端席 
        int R;  // 右端席
        cin >> L >> R;

        people += R - L + 1;

    }

    cout << people << endl;

}