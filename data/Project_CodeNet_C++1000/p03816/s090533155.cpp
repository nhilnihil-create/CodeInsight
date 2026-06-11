#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;  cin >> n;
    map<int,int> mp;
    for (int i = 0; i < n; i++){
        int a;  cin >> a;
        mp[a]++;
    }
    int ans = 0, even = 0;
    for (auto m: mp) {
        if (m.second % 2) {
            m.second = 1;
            ans++;
        }
        else {
            m.second = 2;
            even++;
        }
    }

    if (even % 2)
        ans += even-1;
    else 
        ans += even;

    cout << ans << endl;
    return 0;
}