#include <bits/stdc++.h>
using namespace std;

#define DUMP(x) cerr << #x << "=" << x << endl
#define DUMP2(x, y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")"<< endl
#define BINARY(x) static_cast<bitset<16> >(x)

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)

#define in_range(x, y, w, h) (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;
const int INF = 1e9;
typedef pair<int, int> PII;
int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};

int N, M;
const int MAX = 1e5 + 1;


int main()
{
    ios::sync_with_stdio(false);

    cin >> N >> M;
    vector<map<int, int>> cnt(M);
    vector<int> cnt_all(M);
    
    rep(i, N) {
        int X; cin >> X;
        cnt[X % M][X]++;
        cnt_all[X % M]++;
    }

    int ans = 0;
    for (int i=0; i<=M/2; i++) {
        if (i == 0 || i*2 == M) {
            ans += cnt_all[i] / 2;
        } else {
            int a = i, b = M - i;
            if (cnt_all[a] < cnt_all[b]) swap(a, b);
            int ss = cnt_all[a], ts = cnt_all[b];
            int same_match_max = (ss - ts) / 2;
            map<int, int> S = cnt[a];
            for (auto s : S) {
               if (ss > ts && s.second > 1) {
                   int same_match = min(same_match_max, s.second/2);
                   same_match_max -= same_match;
                   ans += same_match;
               } 
            }
            ans += ts;
        }
        // DUMP2(i, ans);
    }

    cout << ans << endl;
}
