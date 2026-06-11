#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    int a[100100];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int status = 0;
    int cnt = 1;
    for (int i = 0; i < N - 1; i++) {
        if (a[i] < a[i+1]) {
            if (status == -1) {
                cnt++;
                status = 0;
            } else {
                status = 1;
            }
        }
        if (a[i] > a[i+1]) {
            if (status == 1) {
                cnt++;
                status = 0;
            } else {
                status = -1;
            }
        }


    }

    cout << cnt << endl;

    return 0;
}