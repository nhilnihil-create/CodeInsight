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

int ask(i64 x){
    cout << "? " << x << endl;
    char res;
    cin >> res;
    if(res=='Y') return 1;
    return 0;
}

void ans(i64 x){
    cout << "! " << x << endl;
}

void solve(){
    if(ask(1000000000)){
        rep(i,0,10){
            if(ask(2*pow(10,i))){
                ans(pow(10,i));
                return;
            }
        }
    }

    i64 lb,ub;
    rep(i,0,10){
        if(!ask(pow(10,i))){
            lb=pow(10,i-1);
            ub=pow(10,i);
            break;
        }
    }

    while(ub-lb>1){
        i64 m=(lb+ub)/2;
        if(ask(m*10)) ub=m;
        else lb=m;
    }
    ans(ub);
}

int main(){
    solve();
    return 0;
}
