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
using namespace std;

vector<vector<long long> > g;
vector<long long> t;
long long ans = 1e9, r;

void get_ans(){
    do{
        long long now = 0;
        for(int i = 1; i < r; ++i) now += g[t[i - 1]][t[i]];
        ans = min(ans, now); 
    } while(next_permutation(t.begin(), t.end()));
}

int main(){
    long long n, m;
    cin >> n >> m >> r;
    t.resize(r);
    for(int i = 0; i < r; ++i){
        cin >> t[i];
        t[i]--;
    }
    g.assign(n, vector<long long>(n, 1e9));
    long long fr, to, c;
    for(int i = 0; i < m; ++i){
        cin >> fr >> to >> c;
        fr--, to--;
        g[fr][to] = c;
        g[to][fr] = c;
    }
    for(int i = 0; i < n; ++i)
       for(int j = 0; j < n; ++j)
           for(int x = 0; x < n; ++x)
               g[j][x] = min(g[j][x], g[j][i] + g[i][x]);
    sort(t.begin(), t.end());
    get_ans();
    cout << ans;
}