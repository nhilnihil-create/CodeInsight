#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t x;
    cin >> x;
    int64_t y = (x / 11) * 2;
    int64_t z = x % 11;
    if (z >= 7) y += 2;
    else if (z != 0) y += 1;
    cout << y << endl;
}