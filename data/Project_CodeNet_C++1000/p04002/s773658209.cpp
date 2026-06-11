#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef set<pii> pset;

int neighbor_search(const pset& bs, int y, int x) {
    int r = 0;
    for(int i=y-1; i<=y+1; i++) for(int j=x-1; j<=x+1; j++) {
        if(bs.find(pii(i, j)) != bs.end()) {
            r++;
        }
    }
    return r;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w, n;
    cin >> h >> w >> n;
    pset blacks;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        blacks.insert(pii(a, b));
    }
    pset visited;
    ll count[10] = {};
    for(auto itr=blacks.begin(); itr!=blacks.end(); ++itr) {
        int a = itr->first, b = itr->second;
        for(int i=max(a-1, 2); i<=min(a+1, h-1); i++) {
            for(int j=max(b-1, 2); j<=min(b+1, w-1); j++) {
                auto pib = visited.insert(pii(i, j));
                if(pib.second) {
                    int r = neighbor_search(blacks, i, j);
                    count[r]++;
                }
            }
        }
    }
    ll s = 0;
    for(int i=1; i<=9; i++) {
        s += count[i];
    }
    count[0] = long(h-2) * long(w-2) - s;
    for(int i=0; i<=9; i++) {
        cout << count[i]<< endl;
    }

}