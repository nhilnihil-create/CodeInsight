#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> lol(n);
    for (int i = 0; i < n; i++) {
        cin >> lol[i];
    }
    sort(lol.begin(), lol.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += lol[i];
    }
    cout << sum;
}