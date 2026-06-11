#include <iostream>
#include <map>
using namespace std;
int main() {
    int n, a;
    cin >> n;
    map<int, int> mp;
    while (cin >> a) {
        mp[a] = (mp[a] + 1) % 2;
    }
    int cnt = 0;
    for (auto iter=mp.begin(); iter!=mp.end(); iter++) {
        cnt += iter->second;
    }
    cout << cnt << endl;
}