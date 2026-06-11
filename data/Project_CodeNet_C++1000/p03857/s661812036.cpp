#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#define REP(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 20)
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね

//ここから編集する
class UnionFind {
public:
    vector<int> p;//p[i]はiの属する組織
    vector<int> psize;

    UnionFind(int n) {
        p = vector<int>(n);
        psize = vector<int>(n, 1);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        return;
    }

    void printState() {
        if (DEBUG) {
            cout << "---" << endl;
            for (int i = 0; i < p.size(); i++) {
                printf("%dの親は%d\n", i, p[i]);
            }
            cout << "---" << endl;
        }
    }

/* xの属する集合を返す */
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

/* yにxを統合する */
    void unite(int x, int y) {
        psize[x] = psize[y] = psize[x] + psize[y];
        p[find(x)] = p[find(y)];
    }

/* xとyが属する集合が同じかを判定する */
    bool same(int x, int y) {
        return find(x) == find(y);
    }

};


int main() {
    int N, K, L;
    cin >> N >> K >> L;
    vector<pair<int, int> > road;
    vector<pair<int, int> > rail;
    REP(i, 0, K) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        road.push_back(make_pair(p, q));
    }
    REP(i, 0, L) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        rail.push_back(make_pair(p, q));
    }

//    sort(road.begin(),road.end());

//    vector<pair<int,int> > dr;
//    REP(i,0,road.size()){
//        if(road[i] == road[i+1]){
//            dr.push_back(road[i]);
//        }
//    }

//    UnionFind u(N);
    UnionFind ar(N);
    UnionFind br(N);

//    REP(i,0,dr.size()){
//        u.unite(dr[i].first,dr[i].second);
//    }
    REP(i, 0, road.size()) {
        ar.unite(road[i].first, road[i].second);
    }
    REP(i, 0, rail.size()) {
        br.unite(rail[i].first, rail[i].second);
    }

//    REP(i,0,u.psize.size()){
//        cout << u.psize[i];
//        if(i != u.psize.size()-1) cout << " ";
//        else cout << endl;
//    }

    map<pair<int, int>, int> m;
    REP(i, 0, N) {
        if (m.find(make_pair(ar.find(i), br.find(i))) == m.end()) {
//            m.insert(make_pair(make_pair(ar.p[i], br.p[i]), 1));
            m.insert(make_pair(make_pair(ar.find(i), br.find(i)), 1));
        } else {
//            m.find(make_pair(ar.p[i], br.p[i]))->second++;
            m.find(make_pair(ar.find(i), br.find(i)))->second++;
        }
    }

    REP(i, 0, N) {
        cout << m.find(make_pair(ar.find(i), br.find(i)))->second;
        if (i != N - 1) cout << " ";
        else cout << endl;
    }

    return 0;
}
