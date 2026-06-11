#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    unsigned long a, b, c;
    cin >> a >> b >> c;
    if(c % 2 == 0 || a % 2 == 0 || b % 2 == 0) {
        cout << 0 << endl;
        return 0;
    } 

    vector<unsigned long> row = {a,b,c};
    sort(row.begin(),row.end());
    cout << row[0] * row[1] <<endl;
}