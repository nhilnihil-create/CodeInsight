#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 998244353;
const int maxn = 3e5 + 5;

void go() {
    int n;
    cin >> n;
    int ans = 0;
    int x = 0;
    f1(n) {
        int v;
        cin >> v;
        if (v == i) {
            if (!x) {
                x = 1;
                ans++;
            }
            else {
                x = 0;
            }
        }
        else {
            x = 0;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
}
