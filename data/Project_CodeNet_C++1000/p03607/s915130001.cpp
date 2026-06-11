#include<iostream>
#include<map>
using namespace std;

int main() {
    int n, a[100010];
    map<int, int> mp{};

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];    
        mp[a[i]]++;
    }

    int ans = 0;
    for (auto u:mp) if(u.second % 2 != 0) ans++;

    cout << ans << endl;

}