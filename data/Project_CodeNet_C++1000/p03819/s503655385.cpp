#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
struct segtree{
    int n;
    T UNIT;
    vector<T> dat;
    segtree(int n_, T unit){
        UNIT = unit;
        n = 1;
        while(n < n_) n *= 2;
        dat = vector<T>(2*n);
        for(int i = 0; i < 2*n-1; i++) dat[i] = UNIT;
    }

    //これを変更
    T calc(T a, T b){
        T ans = a+b;
        return ans;
    }
    void insert(int k, T a){
        dat[k+n-1] = a;
    }
    void update_all(){
        for(int i = n-2; i >= 0; i--){
            dat[i] = calc(dat[i*2+1], dat[i*2+2]);
        }
    }
    
    void update(int k){
        k += n-1;
        dat[k]++;
        while(k > 0){
            k = (k-1)/2;
            dat[k] = calc(dat[k*2+1], dat[k*2+2]);
        }
    }

    //[a, b)
    //区間[a, b]へのクエリに対してはquery(a, b+1, 0, 0, segtree.n)と呼ぶこと
    T query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return UNIT;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = query(a, b, k*2+1, l, (l+r)/2);
            T vr = query(a, b, k*2+2, (l+r)/2, r);
            return calc(vl, vr);
        }
    }
};

typedef pair<int, int> P;

int main(){
    int N, M;
    vector<P> sec[100000];
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int l, r;
        cin >> l >> r;
        sec[r-l].push_back(P(l, r));
    }
    segtree<int> sgtl(M, 0);
    segtree<int> sgtr(M, 0);
    int large_sec = N;
    int narrow_sec = 0;
    for(int i = 1; i <= M; i++){
        int out_sec = 0;
        int narrow_sec_all = 0;
        for(int j = 0; j <= M; j+=i){
            if(j-1 >= 0) out_sec += sgtr.query(0, j, 0, 0, sgtr.n);
            if(j+1 <= M) out_sec += sgtl.query(j+1, M+1, 0, 0, sgtl.n);
            narrow_sec_all += narrow_sec;
        }
        int ans = large_sec+narrow_sec_all-out_sec;
        cout << ans << endl;
        for(int j = 0; j < sec[i-1].size(); j++){
            //cout << sec[i-1][j].first << ' ' << sec[i-1][j].second << endl;
            sgtl.update(sec[i-1][j].first);
            sgtr.update(sec[i-1][j].second);
            narrow_sec++;
            large_sec--;
        }
    }
}