#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#include <cassert>
#include <iterator>
using namespace std;
using VI = vector<int>;

struct LazySegmentTree
{
private:
    int n;
    vector<int> node, lazy;
    
public:
    //初期化
    LazySegmentTree(vector<int> v)
    {
        int sz = (int)v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);
        
        for (int i=0; i<sz; i++) node[i+(n-1)] = v[i];
        for (int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }
    
    //k番目のノードについて遅延評価を行う
    void eval(int k, int l, int r)
    {
        //遅延配列が空でない場合、自ノード及び子ノードへの
        //値の伝播が起こる
        if (lazy[k] != 0) {
            node[k] += lazy[k];
            
            //最下段かどうかのチェックをする
            //子ノードは親ノードの1/2の範囲であるため、
            //伝播させるときは半分にする
            if (r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            
            //伝播が終わったので、自ノードの遅延配列を空にする
            lazy[k] = 0;
        }
    }
    
    //区間加算
    void add(int a, int b, int x, int k=0, int l=0, int r=-1)
    {
        if (r < 0) r = n;
        
        //k番目のノードに対して遅延評価を行う
        eval(k, l, r);
        
        //範囲外なら何もしない
        if (b <= l || r <= a) return;
        
        //完全に被覆しているならば、遅延配列に値を入れた後に評価
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        
        //そうでないならば、子ノードの値を再帰的に計算して、
        //計算済みの値をもらってくる
        else {
            add(a, b, x, 2 * k + 1, l, (l + r) / 2);
            add(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }
    
    //区間和の取得
    int getsum(int a, int b, int k=0, int l=0, int r=-1)
    {
        if (r < 0) r = n;
        
        //関数が呼び出されたらまず評価
        eval(k, l, r);
        
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return node[k];
        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

struct range {
    int w, l, r;
    bool operator<(const range& rhs) const {
        return w < rhs.w;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<range> vs;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        vs.push_back({r - l, l, r});
    }
    
    sort(vs.begin(), vs.end());
    LazySegmentTree counter(vector<int>(m + 1));
    
    int small_range_begin = 0, small_range_end;
    for (int d = 1; d <= m; d++) {
        int cnt = 0;
        int long_range_cnt = n - int(lower_bound(vs.begin(), vs.end(), range({d, 0, 0})) - vs.begin());
        cnt += long_range_cnt;
        small_range_end = n - long_range_cnt;
        for (int i = small_range_begin; i < small_range_end; i++) {
            counter.add(vs[i].l, vs[i].r + 1, 1);
        }
        small_range_begin = small_range_end;
        for (int i = d; i <= m; i += d) {
            cnt += counter.getsum(i, i + 1);
        }
        cout << cnt << endl;
    }
}
