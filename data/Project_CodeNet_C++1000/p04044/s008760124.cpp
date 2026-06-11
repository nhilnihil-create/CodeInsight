#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<string> vec(n);
    for (int i = 0; i < n && cin >> vec[i]; i++);
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
        cout << vec[i];
}
