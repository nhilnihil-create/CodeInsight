#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main() {
    long long A, B, C; cin >> A >> B >> C;
    if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0) cout << 0 << endl;
    else cout << min({A*B, B*C, C*A}) << endl;
}