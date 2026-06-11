#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
  	cin >> a >> b >> c;
    bool flag = false;
    if (a == b + c) {
        flag = true;
    } else if (a + b == c) {
        flag = true;
    } else if (a + c == b) {
        flag = true;
    }

    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}