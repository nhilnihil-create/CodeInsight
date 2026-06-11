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


int main() {
    int H, W, N;
    cin >> H >> W >> N;
//    set<pair<int, int> > s;
//    vector<vector<int> > v(N, vector<int>(2));
//    REP(i, 0, N) {
//        int a, b;
//        cin >> a >> b;
//        s.insert(pair<int, int>(a, b));
//        v[i][0] = a;
//        v[i][1] = b;
//    }
//    vector<int> ans(10,0);
//    REP(i,0,N){
//        int num = 0;
//        for(int j = -1; j <= 1; j++){
//            for(int k = -1; k <= 1; k++){
//                if(s.find(pair<int,int>(v[i][0] + j,v[i][1] + k)) != s.end()){
//                    num++;
//                }
//            }
//        }
//        ans[num]++;
//    }
//
//    REP(i,0,10){
//        cout << ans[i] << endl;
//    }

    map<pair<int, int>, int> m;
    vector<vector<int> > v(N, vector<int>(2));
    REP(i, 0, N) {
        int a, b;
        cin >> a >> b;
//        s.insert(pair<int, int>(a, b));
//        m.insert(make_pair(a,b),m[make_pair(a,b)]+1);
//        m.find(make_pair(a,b))->second++;
//        if(m.find(make_pair(a,b)) == m.end() ){
//            m.insert(make_pair(make_pair(a,b),1));
//        }else{
//            m.find(make_pair(a,b))->second++;
//        }
        for (int k = a - 1; k <= a + 1; k++) {
            for (int j = b - 1; j <= b + 1; j++) {
                if (!(k >= 1 && k <= H && j >= 1 && j <= W)) continue;
                if (m.find(make_pair(k, j)) == m.end()) {
                    m.insert(make_pair(make_pair(k, j), 1));
                } else {
                    m.find(make_pair(k, j))->second++;
                }
            }
        }
        v[i][0] = a;
        v[i][1] = b;
    }

    vector<ll> ans(10, 0);
    ans[0] = (ll)(H - 2) * (W - 2);
    for (auto mapIterator = m.begin(); mapIterator != m.end(); ++mapIterator) {
//        cout << mapIterator->first.first << " " << mapIterator->first.second << endl;
//        cout << mapIterator->second << endl;
        int x = mapIterator->first.first;
        int y = mapIterator->first.second;
        if (!(x >= 2 && x <= H - 1 && y >= 2 && y <= W - 1)) continue;
        ans[0]--;
        ans[mapIterator->second]++;
    }


//    for(int i = 1+1; i <= H-1; i++){
//        for(int j = 1+1; j <= W-1; j++){
//            if(m.find(make_pair(i,j)) == m.end()) ans[0]++;
//            else ans[m.find(make_pair(i,j))->second]++;
//        }
////        cout << endl;
//    }

    REP(i, 0, 10) cout << ans[i] << endl;
    return 0;
}
