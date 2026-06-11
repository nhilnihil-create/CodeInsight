#include <iostream>
#include <set>

using namespace std;

int sum(int arr1[], int n, int a, int b) {
    int x = arr1[a - 1];
    arr1[a - 1] = b;
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        sm += arr1[i];
    }
    arr1[a-1] = x;
    return sm;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int t;
    cin >> t;
    for (int j = 0; j < t; ++j) {
        int a, b;
        cin >> a >> b;
        cout << sum(arr, n, a, b) << '\n';
    }
    return 0;
}


