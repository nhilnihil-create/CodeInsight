#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ALL(x)      (x).begin(),(x).end()
#define REP(i,n)    for(int i=0;i<(n);i++)
#define REP1(i,n)   for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n)   for(int i=(n);i>=0;i--)
#define CLR(a)      memset((a),0,sizeof(a))
#define MCLR(a)     memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

class Human {
public:
    queue<int> a;

    Human(VLL _a) {
        REP(i, _a.size()) a.push(_a[i]);
    }

    int next() {
        if(a.empty()) return -1;
        int res = a.front();
        a.pop();

        return res;
    }
};

set<int> used_list;
vector<Human> memo[301];

void solve(long long N, long long M, std::vector<std::vector<long long>> A){
    REP(i, N) {
        Human human(A[i]);
        int idx = human.next();
        memo[idx].PB(human);
    }

    int result = INF;
    REP(i, M) {
        int target_idx = 0;
        int max_size = 0;

        REP1(j, M+1) {
            if (max_size < (int) (memo[j].size())) {
                target_idx = j;
                max_size = memo[j].size();
            }
        }

        result = min(result, max_size);
        bool valid = true;
        used_list.insert(target_idx);

        REP(j, memo[target_idx].size()) {
            while(true) {
                int next_idx = memo[target_idx][j].next();
                if(next_idx == -1) {
                    cout << result << endl;
                    return;
                }
                if(used_list.count(next_idx) == 0) {
                    memo[next_idx].PB(memo[target_idx][j]);
                    break;
                }
            }
        }

        memo[target_idx].clear();
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<std::vector<long long>> A(N, std::vector<long long>(M));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%lld",&A[i][j]);
        }
    }
    solve(N, M, std::move(A));
    return 0;
}
