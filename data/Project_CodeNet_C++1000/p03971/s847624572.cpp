#include <iostream>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int sum = 0, sumB = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'a') {
            if (sum < a+b) {
                sum++;
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (s[i] == 'b') {
            if (sum < a+b) {
                if (sumB < b) {
                    sum++;
                    sumB++;
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
}