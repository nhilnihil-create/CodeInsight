#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <complex>
#include <numeric>
#include <cstdio>
#include <iomanip>
#include <random>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR 
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long int;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;

void solve() {
    int n,k,a,b;
    cin >> n >> k;
    map<int,LL> m;
    REP(i,0,n) {
        cin >> a >> b;
        if (a > k) continue;
        m[a] += b;
    }
    set<int> s;
    s.insert(k);
    REP(i,0,30) {
        if (!(k & (1<<i))) continue;
        s.insert((k & ~(1<<i)) | ((1<<i)-1));
    }
    LL ans = 0;
    for (const int &t: s) {
        //dump(t);
        LL sum = 0;
        for (const auto &p: m) {
            int a = p.first;
            LL b = p.second;
            if ((t | a) != t) continue;
            sum += b;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main() {
    solve();
    
    return 0;
}