#include <bits/stdc++.h>
#define endl '\n'
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    if (N >= 64) {
        cout << "64" << endl;
    } else if (N >= 32) {
        cout << "32" << endl;
    } else if (N >= 16) {
        cout << "16" << endl;
    } else if (N >= 8) {
        cout << "8" << endl;
    } else if (N >= 4) {
        cout << "4" << endl;
    } else if (N >= 2) {
        cout << "2" << endl;
    } else {
        cout << "1" << endl;
    }
}
