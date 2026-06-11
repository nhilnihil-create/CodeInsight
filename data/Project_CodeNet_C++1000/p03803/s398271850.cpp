#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    if (a == b) cout << "Draw";
    else if (a < b && a != 1 || b == 1) cout << "Bob";
    else cout << "Alice";
}