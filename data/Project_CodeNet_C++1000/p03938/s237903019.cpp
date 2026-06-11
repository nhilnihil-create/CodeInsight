#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <utility>
#define sign(a) ((a>0)-(a<0))
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define LL long long
#define INF (LL)(1LL<<60)
#define all(a) a.begin(), a.end()
#define gr greater<LL>()

using namespace std;

template <class T>
class SegTree{
public:
    vector<T> arr;
    function<T(T,T)> f;
    T ini;
    uint n;
    SegTree(int N, function<T(T,T)> func, T ini_){
        f=func;
        ini=ini_;
        n=1;
        while(n<N)n<<=1u;
        arr.assign(2*n-1, ini);
    }

    void update(uint i, T val){
        i+=n-1;
        arr[i]=val;
        while(i>0){
            i=(i-1)/2;
            arr[i]=f(arr[2*i+1],arr[2*i+2]);
        }
    }

    T find(uint s, uint t){
        return __find(s,t,0,0,n);
    }
private:
    T __find(uint s, uint t, uint k, uint l, uint r){
        if(t<=l || s>=r)return ini;
        if(s<=l && t>=r)return arr[k];
        T vl=__find(s,t,2*k+1,l,(l+r)/2);
        T vr=__find(s,t,2*k+2, (l+r)/2, r);
        return f(vl,vr);
    }
};

void solve(long long N, std::vector<long long> p){
    SegTree<LL> st(N, [](LL a, LL b){return a+b;}, 0);
    rep(i,N)st.update(i,1);

    LL prev=0;
    for(auto pp:p){
        LL aa = st.find(0, pp);
        LL bb = st.find(pp-1, N);
        if(aa+bb <= prev){
            LL d = prev-(aa+bb)+1;
            st.update(pp-1,1+d);
            prev = aa+bb+2*d;
        }else {
            prev = aa + bb;
        }
    }
    rep(i,N)cout << st.find(0, i+1) << " ";
    cout << endl;
    rep(i,N)cout << st.find(i,N) << " ";
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> p(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&p[i]);
    }
    solve(N, std::move(p));
    return 0;
}
