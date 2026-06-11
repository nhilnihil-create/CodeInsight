#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    if (n%2 == 1) {
        for (int i=n-1; i>=0; i-=2) {
            cout << a[i] << " ";
        }
        for (int i=1; i<=n-2; i+=2) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        for (int i=n-1; i>=1; i-=2) {
            cout << a[i] << " ";
        }
        for (int i=0; i<=n-2; i+=2) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}