#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include<queue>
#include<stack>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1()
{
    int h, w; cin >> h >> w;

    vector<vector<char>> c(h, vector<char>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> c[i][j]; 
        }
    }

    rep(i, h)
    {
        rep(j, w)
        {
            cout << c[i][j];
        }
        cout << endl;
        rep(j, w)
        {
            cout << c[i][j];
        }
        cout << endl;
    
    }

   
}

int main()
{
    solve1();
}