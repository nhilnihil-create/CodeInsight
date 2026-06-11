#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 200001;

int n, k, tree[4 * N];
vector <int> a;

void update(int l, int r, int node, int idx){
    if(r < l || r < idx || l > idx) return;
    if(l == r){
        tree[node]++;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, 2 * node, idx);
    update(mid + 1, r, 2 * node + 1, idx);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int query(int l, int r, int node, int s, int e){
    if(r < l || r < s || l > e) return 0;
    if(s <= l && r <= e) return tree[node];
    int mid = (l + r) / 2;
    return query(l, mid, 2 * node, s, e) + query(mid + 1, r, 2 * node + 1, s, e);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a.resize(n);
    for(auto &i : a){
        cin >> i;
        i -= k;
    }
    vector <ll> b;
    b.push_back(0);
    for(auto &i : a){
        b.push_back(b.back() + i);
    }
    map <ll, int> mp;
    for(auto &i : b) mp[i];
    int x = 0;
    for(auto &i : mp) i.second = x++;
    for(auto &i : b) i = mp[i];
    ll ans = 0;
    for(auto &i : b){
        ans += query(0, n, 1, 0, i);
        update(0, n, 1, i);
    }
    cout << ans << endl;
}
