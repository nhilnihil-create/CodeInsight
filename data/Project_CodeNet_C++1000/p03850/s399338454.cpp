#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
ll sm = 0;
int main(){
    int n;
    cin >> n;
    cin >> sm;
    vector<bool> op(n-1);
    vector<ll> p(n-1);
    rep(i,n-1){
        char c;
        cin >> c;
        if(c=='-'){
            op[i] = 1;
        }else{
            op[i] = 0;
        }
        cin >> p[i];
    }
    vector<pair<ll,ll> > a;
    bool flag = 1;
    ll tmp  = 0;
    ll tt = 0;
    rep(i,n-1){
        if(op[i]){
            if(!flag){
                a.push_back(MP(tt,tmp));
            }
            flag = 0;
            tt = p[i];
            tmp = p[i];
            sm += p[i];
        }else{
            if(flag){
                sm += p[i];
            }else{
                tmp += p[i];
                sm += p[i];
            }
        }
    }
    if(!flag){
        a.push_back(MP(tt,tmp));
    }
    ll mx = -(1LL<<60);
    if(a.size()==0){
        mx = sm;
    }else{
        for(auto x:a){
            ll ss = x.first;
            ll ssss = x.second;
            chmax(mx,sm - ssss*2);
            sm -= 2*ss;
        }
    }
    cout << mx << endl;
    return 0;
}