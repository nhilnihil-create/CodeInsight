#include <bits/stdc++.h>

using namespace std;


int main() {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    vector<int> vec = {};

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);

    sort(vec.begin(), vec.end());

    cout << vec.at(0) + vec.at(1) << endl;
}