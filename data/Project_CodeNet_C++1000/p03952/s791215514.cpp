#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int maxn = 1e6 + 5;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    n = n * 2 - 1;
    if (k == 1 || k == n) {
        cout << "No\n";
        exit(0);
    }
    cout << "Yes\n";
    if (n == 3) {
        cout << "1\n2\n3\n";
        exit(0);
    }
    int ans[n + 5] = {};
    int u[n + 5] = {};
    ans[n/2] = k;
    ans[n/2-1] = k - 1;
    ans[n/2+1] = k + 1;
    u[k] = 1;
    u[k + 1] = 1;
    u[k - 1] = 1;
    if (k == 2) {
        ans[n/2-2] = k + 2;
        u[k+2] = 1;
    }
    else {
        ans[n/2+2] = k - 2;
        u[k-2] = 1;
    }
    int ptr = 1;
    f(n) {
        if (ans[i])continue;
        while(u[ptr]) {
            ptr++;
        }
        u[ptr] = 1;
        ans[i] = ptr;
    }
    f(n) {
        cout << ans[i] << '\n';
    }
}