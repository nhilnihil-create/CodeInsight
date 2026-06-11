#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    vector<int> a(3), b = {5, 5, 7};
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(all(a));
    if(a == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}