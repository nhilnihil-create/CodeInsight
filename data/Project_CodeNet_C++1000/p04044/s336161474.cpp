#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    string a;
    int h, j;
    cin >> h >> j;
    vector<string> v;
    for (int i = 0; i < h; i++) {
        string b;
        cin >> b;
        v.push_back(b);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        a += v[i];
    }
    cout << a;
}
