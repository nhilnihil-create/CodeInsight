#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
#include <climits>
using namespace std; 
#define ll long long int

struct pt{
    ll a, b, c;
};

int main(){
    ll n, ma, mb;
    cin >> n >> ma >> mb;
    vector<pt> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i].a >> p[i].b >> p[i].c;
    vector<vector<vector<ll> > > d(n + 1, vector<vector<ll> >(401, vector<ll>(401, 1e9)));
    d[0][0][0] = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i; j >= 0; --j)
            for(int x = 0; x + p[i].a <= 400; ++x)
                for(int y = 0; y + p[i].b <= 400; ++y){
                    d[j + 1][x + p[i].a][y + p[i].b] = min(d[j + 1][x + p[i].a][y + p[i].b], d[j][x][y] + p[i].c);
                }
    
    ll ans = 1e9;
    for(int i = 1; i <= 40; ++i){
        if(ma * i > 400 || mb * i > 400) break;
        for(int j = 1; j <= n; ++j){
            ans = min(ans, d[j][ma * i][mb * i]);
        }
    }
    cout << (ans == 1e9? -1:ans);
}
