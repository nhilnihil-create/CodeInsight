#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<vector<int>> modM(m);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        modM[x%m].emplace_back(x);
    }

    for(int i=0; i<m; i++){
        sort(modM[i].begin(), modM[i].end());
    }

    int half = m / 2;
    int ans = modM[0].size() / 2;
    for(int i=1; i<=half; i++){
        int small = i, big = m - i;
        int smallsz = modM[small].size(), bigsz = modM[big].size();

        if(smallsz == bigsz){
            if(small == big) ans += smallsz / 2;
            else ans += smallsz;
            continue;
        }

        if(smallsz > bigsz){
            int maxmatch = 0;
            for(int j=0; j<smallsz; j++){
                int cnt = 1, cur = modM[small][j];
                while(j + 1 < smallsz && cur == modM[small][j+1]){
                    j++;
                    cnt++;
                }
                maxmatch += cnt / 2;
            }

            ans += bigsz;

            int rest = smallsz - bigsz;
            ans += min(rest / 2, maxmatch);
        }
        else{
            int maxmatch = 0;
            for(int j=0; j<bigsz; j++){
                int cnt = 1, cur = modM[big][j];
                while(j + 1 < bigsz && cur == modM[big][j+1]){
                    j++;
                    cnt++;
                }
                maxmatch += cnt / 2;
            }

            ans += smallsz;

            int rest = bigsz - smallsz;
            ans += min(rest / 2, maxmatch);
        }
    }

    cout << ans << endl;

    return 0;
}