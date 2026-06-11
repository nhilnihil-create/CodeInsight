#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    map<int, int> mp;
    rep(i, 0, n) {
        mp[a[i]]++;
    }
    
    if(n == mp.size()) {
        cout << n << endl;
    }
    else {
        if(mp.size()%2 == 1) {
            cout << mp.size() << endl;
        }
        else {
            cout << mp.size()-1 << endl;
        }
    }
    return 0;
}