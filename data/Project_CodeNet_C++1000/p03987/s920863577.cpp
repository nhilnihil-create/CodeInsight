#include "bits/stdc++.h"
using namespace std;
#define Rep(i,n) for(int i=0;i<(int)(n);i++)
#define For(i,n1,n2) for(int i=(int)(n1);i<(int)(n2);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i,n) for(ll i=((ll)(n)-1);i>=0;i--)
#define FOR(i,n1,n2) for(ll i=(ll)(n1);i<(ll)(n2);i++)
#define RFOR(i,n1,n2) for(ll i=((ll)(n1)-1);i>=(ll)(n2);i--)
#define put(a) cout<<a<<"\n"
#define all(a)  (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define oorret 0
#define oor(x) [&](){try{x;} catch(const out_of_range& oor){return oorret;} return x;}()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b){a=b;return 1;}return 0;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
T up(const T& l, const T& r) {//SegmentTreeのupdate関数
    T res;
    res = l+r;
    return res;
}

template<typename T, typename Up, typename Eval>
class SegmentTree{
private:
    const Up up; // 更新関数
    const Eval eval; // 評価関数
    std::vector<T> seg;
    std::vector<int> index;
public:
    int sz = 1; //　配列長n以上の最小の2冪
    const T unit; // 評価関数の単位元
    explicit SegmentTree(int n,Up&& f,Eval&& g,T unit=0)noexcept:
    up(std::forward<Up>(f)), eval(std::forward<Eval>(g)),unit(unit){
        while (sz < n) sz <<= 1;
        seg.resize(sz * 2, unit);
        index.resize(sz * 2, unit);
    }
    explicit SegmentTree(std::vector<T> ary,Up&& f,Eval&& g,T unit=0)noexcept:
    up(std::forward<Up>(f)), eval(std::forward<Eval>(g)), unit(unit){
        const int n = (int)ary.size();
        while (sz < n) sz <<= 1;
        seg.resize(sz * 2, unit);
        index.resize(sz * 2, unit);
        init(ary);
    }
    void init(std::vector<T> ary){ // aryで初期化する
        const int n = (int)ary.size();
        for(int64_t i=0;i<n;++i){
            set(i,ary[i]);
        }
        for(int64_t i=sz-2;i>=0;--i){
            eval(seg[2*i+1], seg[2*i+2]);
        }
    }
    void update(int k, T v) {// k番目の値をup(seg[k],v)にする
        k += sz - 1;
        seg[k] = up(seg[k], v);
        while (k > 0) {
            k = (k - 1) / 2;
            seg[k] = eval(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }
    inline void set(const int& k, const T& x) {// 左からk番目の葉にxを代入する
        seg[sz - 1 + k] = x;
    }
    T get(const int& k) {// 左からk番目の葉を得る
        return seg[sz - 1 + k];
    }
    T query_rec(int a, int b) {// [a,b)のupの合成を求める
        int k = 0, l = 0, r = sz;
        return query_rec(a, b, k, l, r);
    }
    T query_rec(int a, int b, int k, int l, int r) {// [a,b)のupの合成を求める(a,b,0,0,sz)のように使う
        if (r <= a || b <= l) {
            return unit;
        }
        if (a <= l && r <= b) {
            return seg[k];
        }
        else {
            T vl = query_rec(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_rec(a, b, k * 2 + 2, (l + r) / 2, r);
            return eval(vl, vr);
        }
    }
    T query(int l,int r){// [l,r)
        l += sz;
        r += sz;
        //vector<int> index;
        int cnt = 0;
        T res = unit;
        for (;l<r; l>>=1, r>>=1) {
            if(r&1){
                index[cnt++]=--r-1;
                //res = eval(res,seg[--r-1]);
                //index.push_back(--r);
            }
            if(l&1){
                index[cnt++]=l++-1;
                //res = eval(res,seg[l++-1]);
                //index.push_back(l++);
            }
        }
        reverse(index.begin(),index.begin()+cnt);
        for(int i=0;i<cnt;++i){
            res = eval(res,seg[index[i]]);
        }
        /*T res=unit;
        for(int i=0;i<index.size();++i){
            res = eval(res,seg[index[i]-1]);
        }*/
        return res;
    }
};

template<typename T,typename Up,typename Eval>
constexpr static inline SegmentTree<T, Up, Eval>
makeSegmentTree(int n,Up&& up,Eval&& eval,T unit=0) noexcept {
    return SegmentTree<T,Up,Eval>(n,std::forward<Up>(up),std::forward<Eval>(eval),unit);
}

template<typename T,typename Up,typename Eval>
constexpr static inline SegmentTree<T, Up, Eval>
makeSegmentTree(std::vector<T> ary,Up&& up,Eval&& eval,T unit=0) noexcept {
    return SegmentTree<T, Up,Eval>(ary,std::forward<Up>(up),std::forward<Eval>(eval),unit);
}
template<typename T,typename U>
int lower_bound_sg(U& sg,T c,int n){//各点0,1が格納されていて、累積和がcと一致する最小のindexを返す
    int sz = sg.sz;
    int lb = -1;
    int ub = n+2;
    while(ub-lb>1){
        int mid = (lb+ub)/2;
        int temp = sg.query(0, mid);//[0,mid)の和
        if(temp<c){
            lb = mid;
        }else{
            ub = mid;
        }
    }
    return lb;
}

int main(){
    int n;
    cin >> n;
    vector<P> p(n);
    REP(i,n){
        cin >> p[i].first;
        p[i].second = i+1;
    }
    sort(all(p));
    using type = int;
    auto add = [](type& a,type b){
        return a+b;
    };
    auto assign = [](type& a,type b){
        return b;
    };
    auto sg = makeSegmentTree(n,assign,add,0);

    ll res = 0;
    sg.update(0,1);
    sg.update(n+1,1);
    int sz = sg.sz;
    Rep(i,n){
        int temp = sg.query(0,p[i].second);
        int t = p[i].second-lower_bound_sg(sg,temp,n);
        int t2= lower_bound_sg(sg,temp+1,n)-p[i].second;
        res+=(double)t*t2*(i+1);
        sg.update(p[i].second,1);
    }
    put(res);
    return 0;
}

