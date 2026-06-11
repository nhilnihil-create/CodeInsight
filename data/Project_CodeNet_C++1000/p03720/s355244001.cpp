#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a[n];
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int cnt[n] = {0};
    for (int i=0; i<n; i++) {
        for (int x: a[i]) cnt[i]++;
    }
    for (int i=0; i<n; i++) cout << cnt[i] << '\n'; 
    
    return 0;
}