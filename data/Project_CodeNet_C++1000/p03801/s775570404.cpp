#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Segtree {
    int n;
    T e;
    vector<T> dat;
    typedef function<T(T a, T b)> Func;
    Func f;

    Segtree(){}
    Segtree(int n_input, Func f_input, T e_input){
        initialize(n_input, f_input, e_input);
    }
    void initialize(int n_input, Func f_input, T e_input){
        f = f_input;
        e = e_input;
        n = 1;
        while(n < n_input) n <<= 1;
        dat.resize(2*n-1, e);
    }

    void update(int k, T a){
        k += n - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1)/2;
            dat[k] = f(dat[2*k+1], dat[2*k+2]);
        }
    }

    T get(int k){
        return dat[k+n-1];
    }

    T between(int a, int b){
        return query(a, b+1, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return e;
        if(a<=l && r<=b) return dat[k];
        T vl = query(a, b, 2*k+1, l, (l+r)/2);
        T vr = query(a, b, 2*k+2, (l+r)/2, r);
        return f(vl, vr);
    }
};

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1);
    for(int i=1; i<=N; i++) cin >> A[i];

    typedef pair<int, int> P;
    Segtree<P> st(N+1, [](auto a, auto b){ return max(a, b); }, {0, 0});
    for(int i=1; i<=N; i++) st.update(i, {A[i], -i});

    int now = N+1;
    int64_t fix = 0;
    vector<int64_t> ans(N+1);
    priority_queue<int64_t> que;
    while(now > 0){
        int nxt = -st.between(0, now-1).second;
        for(int i=nxt; i<now; i++) que.push(A[i]);

        if(now <= N){
            ans[now] += fix * (A[now] - A[nxt]);
            while(que.size() && que.top() >= A[nxt]){
                int64_t a = que.top(); que.pop();
                ans[now] += a - A[nxt];
                fix++;
            }
        }
        now = nxt;
    }

    for(int i=1; i<=N; i++) cout << ans[i] << endl;
}