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
using namespace std;
const int maxn = 10005;
const int mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n;
    while (cin >> n) {
        set<int>v1,v2;
        vector<int>tar;
        f1(n) {
            int x;
            cin >> x;
            if (i & 1) {
                v1.insert(x);
            }
            else {
                v2.insert(x);
            }
            tar.pb(x);
        }
        sort(all(tar));
        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            if ((i & 1) && !v2.count(tar[i])) {
                ans++;
            }
            if (!(i & 1) && v2.count(tar[i])) {
                ans++;
            }
        }
        cout << ans/2 << '\n';
    }
}