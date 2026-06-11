#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<typename Monoid,typename F>
class SegmentTree{
private:
    int sz;
    vector<Monoid> seg;
    const F op;
    const Monoid e;
public:
    SegmentTree(int n,const F op,const Monoid &e):op(op),e(e){
        sz = 1;
        while(sz<=n) sz <<= 1;
        seg.assign(2*sz,e);
    }
    void set(int k, const Monoid &x){
        seg[k+sz] = x;
    }
    void build(){
        for(int i=sz-1;i>0;i--){
            seg[i] = op(seg[2*i],seg[2*i+1]);
        }
    }
    void update(int k,const Monoid &x){
        k += sz;
        seg[k] += x;
        while(k>>=1){
            seg[k] = op(seg[2*k],seg[2*k+1]);
        }
    }
    Monoid query(int l,int r){
        Monoid L = e,R = e;
        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1){
            if(l&1) L = op(L,seg[l++]);
            if(r&1) R = op(seg[--r],R);
        }
        return op(L,R);
    }
    Monoid operator[](const int &k)const{
        return seg[k+sz];
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vvec<int> Llist(M+1);
    for(int i=0;i<N;i++){
        int l,r;
        cin >> l >> r;
        Llist[l].push_back(r);
    }
    vec<int> ans(M+1);
    struct query{
        int r,d;
    };
    vvec<query> Q(M+2);
    for(int d=1;d<=M;d++){
        for(int l=0;l<=M;l+=d){
            int r = l+d;
            if(r>M) r = M+1;
            Q[l].push_back({r,d});
        }
    }
    auto op = [](int a,int b){return a+b;};
    SegmentTree<int,decltype(op)> seg(M+2,op,0);
    for(int l=M;l>=0;l--){
        for(auto& q:Q[l]){
            ans[q.d] += seg.query(0,q.r);
        }
        for(auto& r:Llist[l]) seg.update(r,1);
    }
    for(int i=1;i<=M;i++) cout << N-ans[i] << "\n";
}