#include <bits/stdc++.h>
using namespace std;

class segtree{
    int *tree;
    size_t len, depth;
public:
    segtree(size_t n_){
        for(len=depth=1;len<n_;len<<=1) ++depth;
        tree = new int[2*len];
        for(size_t i=0;i<2*len;++i) tree[i] = 0;
    }

    void add(size_t left, size_t right, int val){
        left += len;
        right += len;
        for(size_t d=0;d<depth;++d){
            if(right <= left) return;
            if(left + 1 == right){
                tree[left] += val;
                return;
            }
            if(left & 1){
                tree[left] += val;
                ++left;
            }
            left >>= 1;
            if(right & 1) tree[right-1] += val;
            right >>= 1;
        }
    }

    void add(size_t pos, int val){
        tree[len+pos] += val;
    }

    int get(size_t pos){
        pos += len;
        for(size_t d=depth-1;d>0;--d){
            size_t p = pos >> d;
            tree[2*p+0] += tree[p];
            tree[2*p+1] += tree[p];
            tree[p] = 0;
        }
        return tree[pos];
    }
};

int main(){
    int n, m;
    vector<pair<int,pair<int,int>>> area;

    cin >> n >> m;
    segtree st(m+1);

    for(int i=0;i<n;++i){
        int l, r;
        cin >> l >> r;
        area.push_back({r-l+1, {l, r}});
    }
    sort(area.begin(), area.end());

    int p = 0;
    for(int d=1;d<=m;++d){
        for(;p<n && area[p].first<d;++p){
            st.add(area[p].second.first, area[p].second.second+1, 1);
        }
        int ans = n - p;
        for(int pos=d;pos<=m;pos+=d) ans += st.get(pos);
        cout << ans << endl;
    }
    
    return 0;
}
