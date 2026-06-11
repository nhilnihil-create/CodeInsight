/*
god taekyu
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,m;
int A[100005];

struct node {
    ll val,t;
} seg[800005];
node B[200005];
void updt1(int idx,int s,int e,int l,int r) {
    //for(int i=l;i<=r;i++) B[i].t++;
    if(e<l || r<s) return;
    if(l<=s && e<=r) {
        seg[idx].t++;
        return;
    }
    updt1(idx*2,s,(s+e)/2,l,r);
    updt1(idx*2+1,(s+e)/2+1,e,l,r);
}
void updt2(int idx,int s,int e,int l,int r,int v) {
    //for(int i=l;i<=r;i++) B[i].val+=v;
    if(e<l || r<s) return;
    if(l<=s && e<=r) {
        seg[idx].val+=(ll)v;
        return;
    }
    updt2(idx*2,s,(s+e)/2,l,r,v);
    updt2(idx*2+1,(s+e)/2+1,e,l,r,v);
}
ll q1(int idx,int s,int e,int x) {
    if(s==e) return seg[idx].t;
    if(x<=(s+e)/2) return seg[idx].t + q1(idx*2,s,(s+e)/2,x);
    else return seg[idx].t + q1(idx*2+1,(s+e)/2+1,e,x);
}
ll q2(int idx,int s,int e,int x) {
    if(s==e) return seg[idx].val;
    if(x<=(s+e)/2) return seg[idx].val + q2(idx*2,s,(s+e)/2,x);
    else return seg[idx].val + q2(idx*2+1,(s+e)/2+1,e,x);
}
ll query(int idx) {
    ll t1 = q1(1,1,2*m,idx);
    ll t2 = q2(1,1,2*m,idx);
    return t1 * idx + t2;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>A[i];
    ll sum = 0;
    for(int i=0;i<n-1;i++) {
        int l = A[i], r = A[i+1];
        if(l > r) r += m;
        sum += r-l;
    }
    for(int i=0;i<n-1;i++) {
        int l = A[i], r = A[i+1];
        if(l > r) r += m;
        updt1(1,1,2*m,l+1,r);
        updt2(1,1,2*m,l+1,r,-(l+1));
    }
    ll _max = 0;
    for(int i=1;i<=m;i++) {
        _max = max(_max , query(i) + query(i+m));
    }
    cout<<sum - _max;
    return 0;
}

/*
god taekyu
*/
