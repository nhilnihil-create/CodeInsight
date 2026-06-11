#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int l[300005], r[300005];

int st[400004], lazy[400004];
void push(int n, int s, int e, int val){
    st[n] += val;
    if(s != e){
        lazy[n+n] += val;
        lazy[n+n+1] += val;
    }
    lazy[n] = 0;
}
void update(int n, int s, int e, int l, int r, int v){
    push(n, s, e, lazy[n]);
    if(s > r || l > e) return;
    if(l <= s && e <= r){
        push(n, s, e, v);
        return;
    }
    int mid = (s+e)/2;
    update(n+n, s, mid, l, r, v);
    update(n+n+1, mid+1, e, l, r, v);
    st[n] = st[n+n] + st[n+n+1];
}
int query(int n, int s, int e, int l, int r){
    push(n, s, e, lazy[n]);
    if(s > r || l > e) return 0;
    if(l <= s && e <= r) return st[n];
    int mid = (s+e)/2;
    return query(n+n, s, mid, l, r) + query(n+n+1, mid+1, e, l, r);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d%d", &l[i], &r[i]);
        v[r[i]-l[i]+1].emplace_back(i);
    }
    int ans = n;
    for(int d=1;d<=m;d++){
        for(int i=0;i<v[d-1].size();i++){
            int j = v[d-1][i];
            update(1, 1, m, l[j], r[j], 1);
            ans--;
        }
        int res = ans;
        for(int i=d;i<=m;i+=d){
            res += query(1, 1, m, i, i); 
        }
        printf("%d\n", res);
    }
}