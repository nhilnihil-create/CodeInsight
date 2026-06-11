#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    // std::greater<type>
    // (x,y) := x > y と等価
    // 降順ソート
    sort(a.begin(),a.end(),greater<int>());
    ll w = 0;
    ll h = 0;
    rep(i,n-1) {
        if (a[i] == a[i+1]) {
            if (w == 0) w = a[i];
            else if (h == 0) h = a[i];
            i++;
        }
        if (h != 0) break;
    }
    cout << h*w << endl;
    return 0;
}