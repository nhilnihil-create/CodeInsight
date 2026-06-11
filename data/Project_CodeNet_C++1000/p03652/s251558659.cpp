#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define EACH(e,v) for(auto& e:v)
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort((v).rbegin(),(v).rend())
#define PERM(v) SORT(v);for(bool c##p=1;c##p;c##p=next_permutation(ALL(v)))
#define UNIQUE(v) SORT(v);(v).erase(unique(ALL(v)),(v).end())
template<typename A,typename B> inline bool chmax(A &a,const B &b){if(a<b){a=b;return 1;}return 0;}
template<typename A,typename B> inline bool chmin(A &a,const B &b){if(a>b){a=b;return 1;}return 0;}

const int MOD = (int)1e9 + 7;
const int INF = 1 << 30;
const ll INFF = 1LL << 62;

int N, M;
vector<vector<int>> A;

bool check(int mid) {
    set<int> ng;
    queue<int> q[N];
    REP(i, N) {
        REP(j, M) {
            q[i].emplace(A[i][j]);
        }
    }
    while (true) {
        vector<int> v(M + 1, 0);
        REP(i, N) {
            v[q[i].front()]++;
        }
        int mx = *max_element(v.begin(), v.end());
        if (mx <= mid) {
            break;
        } else {
            int piv = 0;
            while (v[piv] != mx) ++piv;
            ng.insert(piv);
            REP(i, N) {
                while (ng.count(q[i].front())) {
                    q[i].pop();
                    if (q[i].size() == 0) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

signed main() {

    cin >> N >> M;

    A.resize(N);
    REP(i, N) {
        A[i].resize(M);
        REP(j, M) cin >> A[i][j];
    }

    ll ok = N, ng = 0;
    while (abs(ok - ng) > 1) {
      ll mid = (ok + ng) / 2;
      if (check(mid)) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    
    cout << ok << endl;

}