#include<bits/stdc++.h>
#define maxn 132000
#define endl '\n'
using namespace std;
struct op {
	int l,r;
};
int seg[maxn<<1];
void push(int p,int lch,int rch) {
	seg[lch] += seg[p];
	seg[rch] += seg[p];
	seg[p] = 0;
}
void modify(int l,int r,int ql,int qr,int p) {
	if(l == ql && r == qr) {
		seg[p]++;
	}
	else {
		int mid = (l+r)>>1 , lch = p<<1 , rch = p<<1|1;
		push(p,lch,rch);
		if(qr <= mid)
			modify(l,mid,ql,qr,lch);
		else if(ql > mid)
			modify(mid+1,r,ql,qr,rch);
		else {
			modify(l,mid,ql,mid,lch);
			modify(mid+1,r,mid+1,qr,rch);
		}
	}
}
int query(int l,int r,int pos,int p) {
	if(l == r)
		return seg[p];
	else {
		int mid = (l+r)>>1 , lch = p<<1 , rch = p<<1|1;
		push(p,lch,rch);
		if(pos <= mid)
			return query(l,mid,pos,lch);
		else
			return query(mid+1,r,pos,rch);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<op> ops;
	for(int i=1,l,r;i<=n;i++) {
		cin >> l >> r;
		ops.emplace_back(op{l,r});
	}
	sort(ops.begin(),ops.end(),[=](op a,op b)->bool
		{return a.r - a.l < b.r - b.l;});
	int sum = n , idx = 0;
	for(int d=1;d<=m;d++) {
		while(idx < n && ops[idx].r - ops[idx].l + 1 < d) {
			modify(1,m,ops[idx].l,ops[idx].r,1);
			idx++;
			sum--;
		}
		int ans = sum;
		for(int i=d;i<=m;i+=d)
			ans += query(1,m,i,1);
		cout << ans << endl;
	}
	return 0;
}
