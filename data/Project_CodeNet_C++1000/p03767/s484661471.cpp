#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    int MAX = 3 * N;
    unsigned int a[MAX];

    for (int i = 0; i < MAX; i++) {
        cin >> a[i];
    }
    sort(a, a + MAX);

    unsigned long result = 0;
    for (int i = 0; i < N; i++) {
        result += a[MAX - (2 * i) - 2];
    }

    cout << result << endl;

    return 0;
}
