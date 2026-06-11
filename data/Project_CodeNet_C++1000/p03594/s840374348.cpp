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

/*
    (1,0) => (1,1)
    (0,1) => (-1,1)
    (x,y) => (x-y,x+y)
*/

pair<int,int> rotate45(int y,int x){
    return make_pair(y+x,-y+x);
}

void solve(){
    int H,W,d;
    cin >> H >> W >> d;

    vector<int> ys,xs;
    rep(i,0,H) rep(j,0,W){
        int i_=rotate45(i,j).first,j_=rotate45(i,j).second;
        ys.push_back(i_);
        xs.push_back(j_);
    }

    sort(ys.begin(),ys.end());
    sort(xs.begin(),xs.end());

    ys.erase(unique(ys.begin(),ys.end()),ys.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());

    map<int,int> y_to_order,x_to_order;
    rep(i,0,ys.size()) y_to_order[ys[i]]=i;
    rep(i,0,xs.size()) x_to_order[xs[i]]=i;

    vector<int> color(H*W);
    rep(i,0,H){
        rep(j,0,W){
            int i_=rotate45(i,j).first,j_=rotate45(i,j).second;
            color[i*W+j]=(y_to_order[i_]/d%2+x_to_order[j_]/d*2+2000)%4;
        }
    }

    rep(i,0,H){
        rep(j,0,W){
            if(color[i*W+j]==0) cout << "R";
            else if(color[i*W+j]==1) cout << "Y";
            else if(color[i*W+j]==2) cout << "G";
            else cout << "B";
        }
        cout << endl;
    }
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
