#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;

void solve();

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    int i = 1;
    for(i = 1; i <= n; i++) {
        sum += i;
        if(sum >= n) break;
    }
    bool a[i+1];
    for(int j = 0; j < i; j++) {
        a[j] = true;
    }
    for(int j = i; j >= 1; j--) {
        if(sum - j == n) continue;
        cout << j << endl;
    }

}