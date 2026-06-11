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

// 下にy, 右にx
enum {R, U, L, D};
const int dx[] = {1,  0, -1, 0};
const int dy[] = {0, -1,  0, 1};

int N;
vector<int> A;

signed main() {

    cin >> N;

    A.resize(N);
    REP(i, N) cin >> A[i];

    // 商品単価の最低値
    int mn = 1;

    ll res = 0;
    REP(i, N) {
        // A[i] - 1 つかえる
        // 商品の値段は最低 mn
        if (i == 1) mn = 2;
        if (A[i] == mn) ++mn;
        else if (A[i] > mn) {
            res += (A[i] - 1) / mn;
        }
        // cout << A[i] << ' ' << mn << endl;
    }
    cout << res << endl;

}