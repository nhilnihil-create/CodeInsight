#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxN = 310;

int a[maxN][maxN];
vector<pair<int, int> > rr;
int n;

long long process() {
    long long ans = 0;
    for(auto x : rr) {
        bool found = false;
        for(int i=1; i<=n; i++)
            if (i != x.first && i != x.second)
                if (a[x.first][i] + a[x.second][i] == a[x.first][x.second])
                    found = true;
                else if (a[x.first][i] + a[x.second][i] < a[x.first][x.second])
                    return -1;
        if (!found)
            ans += a[x.first][x.second];
    }
    return ans;
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++) {
            scanf("%d", &a[i][j]);
            if (i < j) 
                rr.push_back(make_pair(i, j));
        }
    sort(rr.begin(), rr.end(), [](pair<int, int> x, pair<int, int> y) -> bool {
            return a[x.first][x.second] < a[y.first][y.second];    
        });
    cout << process();
}
