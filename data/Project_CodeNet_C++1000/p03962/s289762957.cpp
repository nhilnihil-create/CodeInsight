#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> v(100);
    v.at(a - 1)++;
    v.at(b - 1)++;
    v.at(c - 1)++;

    int n = count(v.begin(), v.end(), 0);
    cout << 100 - n << endl;
}