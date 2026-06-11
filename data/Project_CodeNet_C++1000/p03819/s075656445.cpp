#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <set>
#include <cmath>
#include <cassert>
using namespace std;

// 1-indexed
template <class X>
class FenwickTree {
    int n;
    vector<X> a;
public:
    FenwickTree(int n) : n(n), a(n+1, 0) {}
    X get(int i) {
        X sm = 0;
        for(; i > 0; i -= i&-i) sm += a[i];
        return sm;
    }
    void add(int i, X x) {
        for(; i <= n; i += i&-i) a[i] += x;
    }
    X at(int i){return get(i) - get(i-1);}
};

int main(){
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> v(N);
    for(int i=0; i<N; i++){
        int l, r;
        cin >> l >> r;
        int diff = r - l + 1;
        v[i] = make_tuple(diff, l, r);
    }
    sort(v.begin(), v.end());

    int idx = 0;
    FenwickTree<int> ft(M+1);
    int base = N;

    vector<int> ans;
    for(int d=1; d<=M; d++){
        for(int i=idx; i<N; i++){
            int diff, l, r;
            tie(diff, l, r) = v[i];
            if(diff < d){
                base--;
                ft.add(l, 1);
                ft.add(r+1, -1);
                idx = i+1;
            }else break;
        }
        int cnt = 0;
        for(int dd=d; dd<=M; dd+=d){
            cnt += ft.get(dd);
        }
        ans.push_back(cnt+base);
    }
    for(int x : ans)
        cout << x << endl;
    return 0;
}
