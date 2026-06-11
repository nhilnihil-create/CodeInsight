#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(n), b(m);
    for(int i = 0; i < n; i++)cin >> a[i].first >> a[i].second;
    for(int i = 0; i < m; i++)cin >> b[i].first >> b[i].second;


    for(int i = 0; i < n; i++) {
        int ind = -1; int dist = 1e9;
        int x = a[i].first, y = a[i].second;
        for(int j = 0; j < m; j++) {
            if(dist > abs(x - b[j].first) + abs(y - b[j].second)) {
                ind = j;
                dist = abs(x - b[j].first) + abs(y - b[j].second);
            }
        }
        cout << ind + 1 << endl;
    }
}