#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    // p p
    // p n
    // n p
    // n n
    long a, b;
    cin >> a >> b;
    if(a > 0 && b > 0)
        cout << "Positive" << endl;
    else if(a == 0)
        cout << "Zero" << endl;
    else if(a < 0 && b > 0)
        cout << "Zero" << endl;
    else if(b == 0)
        cout << "Zero" << endl;
    else {
        if((abs(a - b) + 1) % 2 == 1)
            cout << "Negative" << endl;
        else
            cout << "Positive" << endl;
    }
}