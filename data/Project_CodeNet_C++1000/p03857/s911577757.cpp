#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define pb push_back
const int maxn = 200005;
const ll mod = 1000000007;
int fa[maxn], fb[maxn];
void init() {
    for (int i = 0; i < maxn; i++) fa[i] = i, fb[i] = i;
}
int fi(int* k, int x) {
    return x == k[x] ? x : k[x] = fi(k, k[x]);
}
void Union(int* k, int x, int y) {
    int fx = fi(k, x), fy = fi(k, y);
    if (fx != fy) k[fy] = fx;
}
map<pair<int, int>, int>mp;
int main() {
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int n, k, l, x, y;
    init();
    cin >> n >> k >> l;
    while (k--) {
        cin >> x >> y;
        Union(fa, x, y);
    }
    while (l--) {
        cin >> x >> y;
        Union(fb, x, y);
    }
    for (int i = 1; i <= n; i++)  mp[make_pair(fi(fa, i), fi(fb, i))]++;
    for (int i = 1; i <= n; i++) cout<<mp[make_pair(fi(fa, i), fi(fb, i))]<<" ";
    cout<< '\n';
    return 0;

}