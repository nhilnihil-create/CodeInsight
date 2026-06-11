#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
const int maxn = 1e5 + 5;
int a[maxn] , pre[maxn] , aft[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n , t; cin >> n >> t;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    pre[0] = 2e9;
    for (int i = 1 ; i <= n ; i++) pre[i] = min(pre[i - 1] , a[i]);
    for (int i = n ; i >= 1 ; i--) aft[i] = max(aft[i + 1] , a[i]);
    int mx = 0;
    for (int i = 1 ; i < n ; i++) {
        mx = max (mx , aft[i + 1] - pre[i]);
    }
    set<pii> Q;
    for (int i = 1 ; i < n ; i++) {
        if (mx == aft[i + 1] - pre[i]){
            Q.insert(mp(aft[i + 1] , pre[i]));
        }
    }
    cout << Q.size()<< endl;
    return 0;
}