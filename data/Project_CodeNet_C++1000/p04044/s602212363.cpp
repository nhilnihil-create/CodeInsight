#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, l;

    cin >> n >> l;
    vector < string > arr(n);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 0; i < n-1; ++i)
        for (int j = n-1; j > i; --j) {
            if (arr[j] < arr[j-1]) {
                string temp;
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }

    for (int i = 0; i < n ; ++i)
        cout << arr[i];
    return 0;
}
