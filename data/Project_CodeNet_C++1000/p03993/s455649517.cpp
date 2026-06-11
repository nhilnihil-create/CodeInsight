#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i]--;

    int ans=0;
    for (int i = 0; i < n; i++) {
        if (a[a[i]] == i) {
            ans++;
        }
    }

    cout << ans/2 << endl;

    return 0;
}