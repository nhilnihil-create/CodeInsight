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
    
    string s;
    cin >> s;
    
    ll ret = 0;
    
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] != s[i - 1])
        {
            ret++;
        }
    }
    
    cout << ret << endl;
    
    return 0;
}