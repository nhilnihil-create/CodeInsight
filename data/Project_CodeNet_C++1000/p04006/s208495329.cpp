#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

struct SegmentTree{
    int leaves;
    vector<int> data;

    void init(int n){
        leaves = 1;
        while(leaves < n) leaves *= 2;// nearest power of 2 (leaf nodes)
        data.assign(2 * leaves, INF);// (0,) 1, ..., 2 * leaves - 1
    }

    // update i-th leaf (0-indexed) to x
    void update(int i, int x){
        i += leaves;
        data[i] = x;
        while(i >= 2){
            i /= 2;// move upward (to the parent node)
            data[i] = min(data[i*2], data[i*2 + 1]);// compare the children
        }
    }

    // minimum [a,b)
    int query(int a, int b, int k, int l, int r){// k-th node of the tree = [l,r)
        if(b <= l || r <= a) return INF;// no overlap
        if(a <= l && r <= b) return data[k];// completely inside
        // otherwise: recursive
        int vl = query(a, b, k*2    , l      , (l+r)/2);// left  child
        int vr = query(a, b, k*2 + 1, (l+r)/2, r      );// right child
        return min(vl, vr);
    }
};

int main(){
    int n;
    long long int x;
    cin >> n >> x;

    SegmentTree seg; 
    seg.init(2*n);

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        seg.update(i, a[i]);
        seg.update(n+i, a[i]);
    }

    long long int ans = 1e18;// INF
    for(int k=0; k<n; k++){
        long long int test = k * x;
        for(int i=0; i<n; i++){
            test += seg.query(i, i+k+1, 1, 0, seg.leaves);// [x,y] -> [x,y+1)
        }
        ans = min(ans, test);
    }
    cout << ans << endl;
    return 0;
}