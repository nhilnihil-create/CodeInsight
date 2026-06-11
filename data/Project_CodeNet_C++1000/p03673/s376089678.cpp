#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>b(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    if (n % 2 == 0){
        for (int i = n-1; i >= 0; i-=2) {
            cout << a.at(i) << ' ';
        }
        for (int i = 0; i < n; i+=2) {
            cout << a.at(i);
            if (i == n-2){
                cout << endl;
            }
            else {
                cout << ' ';
            }
        }
    }
    else {
        for (int i = n-1; i >= 0; i-=2) {
            cout << a.at(i) << ' ';
        }
        for (int i = 1; i < n; i+=2) {
            cout << a.at(i);
            if (i == n-1){
                cout << endl;
            }
            else {
                cout << ' ';
            }
        }
    }
}
