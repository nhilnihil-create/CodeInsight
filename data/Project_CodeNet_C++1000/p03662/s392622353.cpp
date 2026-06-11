#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

#define INIT std::cin.tie(0);std::ios::sync_with_stdio(false);
#define ALL(c) (c).begin(), (c).end()
#define CALL(c) (c).cbegin(), (c).cend()
#define RALL(c) (c).rbegin(), (c).rend()
#define CRALL(c) (c).crbegin(), (c).crend()
#define REP(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define FOR(i, s, n) for (int i = s; i < static_cast<int>(n); i++)
#define ASC(t) [](t& x, t& y){ return x < y; }
#define DESC(t) [](t& x, t& y){ return x > y; }
#define PSORT(s,p,e) partial_sort((s), next((s), (p)), (e))
#define VIEW(v,t) for_each((v).begin(), (v).end(), [](t& a) { cout << a << " "; }); cout << endl;

#define IN(a, x, b) (a<=x && x<b)
template<class T> inline T CHMAX(T& x, const T y){return x=(x<y)?y:x;}
template<class T> inline T CHMIN(T& x, const T y){return x=(x>y)?y:x;}
#define OUT(dist) std::cout<<(dist);
#define WS std::cout<<" ";
#define NL std::cout<<"\n"

using PII = pair<int, int>;
using PLL = pair<long long, long long>;
using LL = long long;
using ULL = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using V2 = vector<vector<T>>;
template<class T, int W=255> using A = array<T, W>;
template<class T, int W=255, int H=255> using A2 = array<array<T, W>, W>;

int N;
V<V<int>> v;
V<int> memo;

void bfs() {
    memo.resize(N+1);
    std::queue<tuple<int,int>> fennec;
    std::queue<tuple<int,int>> snuke;
    fennec.push(make_tuple(1,1));
    memo[1] = 1;
    snuke.push(make_tuple(N,1));
    memo[N] = 2;
    int st = 1;
    while(!fennec.empty() || !snuke.empty()) {
        queue<tuple<int,int>>& q = (st) ? fennec : snuke;
        int n, c;
        std::tie(n,c) = q.front();
        while(!q.empty()) {
            int a, b;
            std::tie(a,b) = q.front();
            if(c != b) break;
            q.pop();
            REP(i,v[a].size()) {
                if(memo[v[a][i]] == 0) {
                    memo[v[a][i]] = (st) ? 1 : 2;
                    q.push(make_tuple(v[a][i],b+1));
                }
            }
        }
        st ^= 1;
    }
}

int main(){
    INIT;
    cin >> N;
    v.resize(N+1);
    REP(i,N-1) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();
    int cnt1 = 0, cnt2 = 0;
    FOR(i,1,N+1) if(memo[i] == 1) cnt1++; else if(memo[i] == 2) cnt2++;

    if(cnt1 > cnt2) cout << "Fennec" << "\n";
    else cout << "Snuke" << "\n";
}