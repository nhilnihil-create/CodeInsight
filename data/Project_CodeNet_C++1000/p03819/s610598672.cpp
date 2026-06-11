#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    // k 番目のノードについて遅延評価を行う
    void eval(int k, int l, int r) {

    // 遅延配列が空でない場合、自ノード及び子ノードへの
    // 値の伝播が起こる
        if(lazy[k] != 0) {
            node[k] += lazy[k];

        // 最下段かどうかのチェックをしよう
        // 子ノードは親ノードの 1/2 の範囲であるため、
        // 伝播させるときは半分にする
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }

        // 伝播が終わったので、自ノードの遅延配列を空にする
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;

    // k 番目のノードに対して遅延評価を行う
        eval(k, l, r);

    // 範囲外なら何もしない
        if(b <= l || r <= a) return;
    
    // 完全に被覆しているならば、遅延配列に値を入れた後に評価
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }

    // そうでないならば、子ノードの値を再帰的に計算して、
    // 計算済みの値をもらってくる
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;

    // 関数が呼び出されたらまず評価！
        eval(k, l, r);

        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }

};



int main() {
    //cout.precision(10);
    int n, m;
    cin >> n >> m;
    priority_queue<i_i, vector<i_i>, greater<i_i> > que;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        que.emplace(r - l + 1, l);
    }
    vector<ll> v(m + 2);
    LazySegmentTree seg(v);
    int ans[300500];
    for(int i = 0; i <= m; i++){
        ans[i] = 0;
    }
    int ok = n;
    for(int i = 1; i <= m; i++){
        while(!que.empty()){
            i_i now = que.top();
            if(now.first >= i) break;
            int l = now.second;
            int r = now.first + now.second;
            //cout << 
            seg.add(l, r, 1);
            que.pop();
            ok--;
        }
        ans[i] = ok;
        for(int j = i; j <= m; j += i){
            ans[i] += seg.getsum(j, j + 1);
        }
        cout << ans[i] << endl;
    }
    return 0;
}
