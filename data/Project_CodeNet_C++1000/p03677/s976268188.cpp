// 00:53~

#include <bits/stdc++.h>
using namespace std;

enum rangeOperaion{
    NUL,
    UPDATE,
    ADD
};
enum rangeOutput{
    MIN,
    MAX,
    SUM
};

using ll = int64_t;
class segTree{
    int N;
    rangeOutput output;
    function<ll(ll,ll)> func;

    ll *tree;
    pair<rangeOperaion, ll> *lazy;
    const pair<rangeOperaion, ll> nullopr=make_pair(NUL, 0);
    pair<int, int> *range;

    int getParent(int child){
        return child/2;
    }
    pair<int,int> getChildren(int parent){
        return make_pair(2*parent, 2*parent+1);
    }
    int lg(ll N){
        int lgN;
        for(lgN=0;(1<<lgN)<N;lgN++);
        return lgN;
    }
    inline ll defaultValue(rangeOutput o){
        if(o==MIN) return INT64_MAX;
        if(o==MAX) return INT64_MIN;
        if(o==SUM) return 0;
    }

    void setLazy(int pos, pair<rangeOperaion, ll> val){
        if(val.first==UPDATE) lazy[pos]=val;
        else if(lazy[pos].first==NUL) lazy[pos]=val;
        else lazy[pos].second+=val.second;
    }
    void eval(int pos){
        if(lazy[pos].first==NUL) return;
        if(pos<N){
            setLazy(getChildren(pos).first, lazy[pos]);
            setLazy(getChildren(pos).second, lazy[pos]);
        }
        if(lazy[pos].first==UPDATE){
            if(output==SUM) tree[pos]=lazy[pos].second*(range[pos].second-range[pos].first);
            else tree[pos]=lazy[pos].second;
        }else{
            if(output==SUM) tree[pos]+=lazy[pos].second*(range[pos].second-range[pos].first);
            else tree[pos]+=lazy[pos].second;
        }
        lazy[pos]=nullopr;
    }

    void operate(ll val, int pos, int left, int right, rangeOperaion op){
        eval(pos);
        if(right<=range[pos].first || range[pos].second<=left) return;
        if(left<=range[pos].first && range[pos].second<=right){
            setLazy(pos, make_pair(op, val));
            eval(pos);
            return;
        }
        operate(val, getChildren(pos).first, left, right, op);
        operate(val, getChildren(pos).second, left, right, op);
        tree[pos]=func(tree[getChildren(pos).first], tree[getChildren(pos).second]);
    }

    ll get(int pos, int left, int right){
        eval(pos);
        if(right<=range[pos].first || range[pos].second<=left) return defaultValue(output);
        if(left<=range[pos].first && range[pos].second<=right) return tree[pos];
        return func(get(getChildren(pos).first, left, right), get(getChildren(pos).second, left, right));
    }

    public:
    segTree(int n, rangeOutput o){
        N=(1LL<<lg(n));
        if(N<n) N*=2;
        tree=new ll[2*N];
        lazy=new pair<rangeOperaion,ll>[2*N];
        range=new pair<int,int>[2*N];

        output=o;
        for(int i=1;i<2*N;i++){
            tree[i]=defaultValue(o);
            lazy[i]=nullopr;
        }
        for(int i=2*N-1;i>0;i--){
            if(i>=N) range[i]=make_pair(i-N, i-N+1);
            else range[i]=make_pair(range[getChildren(i).first].first, range[getChildren(i).second].second);
        }
        
        switch(output){
            case MIN:
                func=[](ll a, ll b){ return a<b?a:b; };
                break;
            case MAX:
                func=[](ll a, ll b){ return a>b?a:b; };
                break;
            case SUM:
                func=[](ll a, ll b){ return a+b; };
                break;
        }
    }
    ~segTree(){
        delete[] tree;
        delete[] lazy;
        delete[] range;
    }
    void update(ll value, int left, int right){
        if(0<=left && left<right && right<=N)
            operate(value, 1, left, right, UPDATE);
    }
    void add(ll value, int left, int right){
        if(0<=left && left<right && right<=N)
            operate(value, 1, left, right, ADD);
    }
    void update(ll value, int pos){
        update(value, pos, pos+1);
    }
    void add(ll value, int pos){
        add(value, pos, pos+1);
    }
    ll queue(int left, int right){
        return get(1, left, right);
    }
    ll queue(int pos){
        return get(1, pos, pos+1);
    }
};

int main(){
    int64_t val1 = 0, cnt = 0;
    static int64_t ddp[100000], dp[100000];
    
    int n, m;
    cin >> n >> m;

    segTree st(m, rangeOutput::SUM);

    int prev;
    cin >> prev;
    for(int i=1;i<n;++i){
        int a;
        cin >> a;
        int d = a - prev;
        while(d < 0) d += m;
        cnt += d;
        if(prev < a) st.add(1, prev + 1, a);
        else{
            st.add(1, prev+1, m);
            st.add(1, 0, a);
        }
        st.add(1-d, a);

        if(a < prev) val1 += d - a;
        prev = a;
    }
    dp[0] = val1;
    for(int i=1;i<m;++i) dp[i] = dp[i-1] + st.queue(i);
    cout << cnt - *max_element(dp, dp+m) << endl;

    return 0;
}