#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int light = 1;
    int arr[N];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        if (light == 2) {
            cout << ans << endl;
            return 0;
        }
        light = arr[light - 1];
        ans++;
    }
    cout << -1 << endl;
    return 0;
}
