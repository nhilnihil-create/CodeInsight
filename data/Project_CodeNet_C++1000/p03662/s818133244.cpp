#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>

using namespace std;

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ; //何もしない文
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#define pb push_back

typedef long long LL; 
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

int d[2][int(1e5)]; // 色
vector<int> v[int(1e5)]; //隣接リスト

void dfs(int x, int y, int z, int w) {
    int i;
    
    d[w][x] = z; // zは距離 wは手番 xは現在地
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue; // 戻るのは許さない
        
        dfs(v[x][i], x, z + 1, w);
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int n, c1 = 0, c2 = 0, i;
    cin >> n;

    for(i = 0; i < n-1; i++)
    {
        int x,y; cin >> x >> y;
        x--; y--;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(0, -1, 0, 0);
    dfs(n - 1, -1, 0, 1);

    for (i = 0; i < n; i++) {
        if (d[0][i] <= d[1][i]) {
            c1++;
        } else {
            c2++;
        }
    }


    if(c1 > c2) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;

}
