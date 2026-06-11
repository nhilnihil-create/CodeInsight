#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long 
#define ret return
#define PB push_back
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define pll pair <long long ,  long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);

const int maxn = 2e5;
vector <int> vec;
int ans[maxn];

int main() {
    int n , x;
    cin >> n >> x;
    if((x == 1) || (x == 2 * n - 1)) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= 2 * n - 1; ++i) {
        if((i != x) && (i != x - 1) && (i != x + 1)) {
            vec.PB(i);
        }
    }
    ans[n] = x; ans[n - 1] = x - 1; ans[n + 1] = x + 1;
    int p = 0;
    for (int i = 1; i <= 2 * n - 1; ++i) {
        if((i == n - 1) || (i == n) || (i == n + 1)) {continue;}
        ans[i] = vec[p];
        p++;
    }
    for (int i = 1; i <= 2 * n - 1; ++i) {cout << ans[i] << endl;}
}