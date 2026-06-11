#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;

vector<ll> dx = {1, -1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

vector<vector<ll>> g;


int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i)
    {
        cin >> a[i];
    }
    map<char, ll> m;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            m[a[i][j]]++;
        }
    }
    
    map<ll, ll> c;
    c[1] = 0;
    if (h % 2 && w % 2)
    {
        c[1] = 1;
    }
    c[2] = 0;
    if (h % 2)
    {
        c[2] += w;
    }
    if (w % 2)
    {
        c[2] += h;
    }
    c[2] -=  2 * c[1];
    c[4] = h * w - c[2] - c[1];
    
    for (auto itr = m.begin(); itr != m.end(); ++itr)
    {
        if (itr->second % 2)
        {
            c[1]--;
            itr->second--;
        }
        
        if (itr->second % 4 != 0 && itr->second >= 2)
        {
            c[2] -= 2;
            itr->second -= 2;
        }
        
        if (c[1] < 0 || c[2] < 0 || c[4] < 0)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    
    return 0;
}