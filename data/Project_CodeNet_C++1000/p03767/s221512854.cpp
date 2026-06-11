#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll N, x, ans;
    cin >> N;

    vector<ll> a;

    for (int i = 0; i < 3*N; i++) {
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end(),std::greater<ll>());
    
    ans = 0;
    for (int i = 0; i < N; i++) {
        ans += a[2*i+1];
    }

    cout << ans << endl;
}
