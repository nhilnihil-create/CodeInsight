#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

using i64=int64_t;

void solve(){
    int N;
    cin >> N;
    vector<i64> A(N);
    vector<char> op(N);
    op[0]='+';
    cin >> A[0];
    rep(i,1,N) cin >> op[i] >> A[i];

    static i64 memo[100001][3];
    static bool done[100001][3];
    fill_n((i64*)memo,100001*3,-inf64);
    fill_n((bool*)done,100001*3,false);
    function<i64(int,int)> rec=[&](int i,int j){
        auto &res=memo[i][j];
        if(done[i][j]) return res;
        done[i][j]=true;
        if(i==N) return res=0;
        int s=op[i]=='-';
        rep(j_,0,j+1){
            res=max(res,((j_+s)%2==0?1:-1)*A[i]+rec(i+1,j_));
            if(s) res=max(res,((j_+s)%2==0?1:-1)*A[i]+rec(i+1,(j_+1==3?1:j_+1)));
        }
        return res;
    };
    cout << rec(0,0) << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}
