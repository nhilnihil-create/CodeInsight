#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int res = 0;
    res =  (b-a + d-c) - (max(b, d) - min(a, c));
    cout << (res >= 0? res: 0) << endl;
}