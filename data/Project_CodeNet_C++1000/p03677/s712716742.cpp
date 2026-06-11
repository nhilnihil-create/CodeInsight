#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

struct Treap{
	struct Node{
		int x, size, fix, y;
		long long sum;
		Node *left, *right;
		Node(){}
		Node(int _x, int _y, Node *l = NULL, Node *r = NULL){
			x = _x, y = _y, left = l, right = r, fix = rand(), sum = y, size = 1;
		}
		long long lsum(){return left ? left->sum : 0;}
		long long rsum(){return right ? right->sum : 0;}
		int lsize(){return left ? left->size : 0;}
		int rsize(){return right ? right->size : 0;}
		void pushup(){sum = lsum() + rsum() + y, size = lsize() + rsize() + 1;}
	}*T;
	typedef pair <Node *, Node *> pnn;
	void init(){T = NULL;}
	Node *merge(Node *l, Node *r){
		if (!l || !r) return l ? l : r;
		if (l->fix > r->fix){
			l->right = merge(l->right, r);
			l->pushup();
			return l;
		} else {
			r->left = merge(l, r->left);
			r->pushup();
			return r;
		}
	}
	pnn split(Node *T, int val){
		if (!T) return pnn(NULL, NULL);
		if (val < T->x){
			pnn tmp = split(T->left, val);
			T->left = tmp.se, T->pushup();
			return mp(tmp.fi, T);
		} else {
			pnn tmp = split(T->right, val);
			T->right = tmp.fi, T->pushup();
			return mp(T, tmp.se);
		}
	}
	void Insert(int x, int y){
		pnn t = split(T, x);
		T = merge(t.fi, merge(new Node(x, y), t.se));
	}
	long long Query(int x){
		pnn t = split(T, x - 1);
		long long ans = !t.se ? 0 : 1ll * x * t.se->size - t.se->sum - t.se->size;
		T = merge(t.fi, t.se);
		return ans;
	}
};

struct Segment_tree{
	Treap T[800010];
	void Build(int now, int l, int r){
		T[now].init();
		if (l == r) return ;
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	void Update(int now, int l, int r, int pos, int x){
//		cout << "Update:" << now << " " << l << " " << r << " " << pos << " " << x << endl;
		T[now].Insert(x, pos);
		if (l == r) return ;
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos, x);
		else Update(now << 1 | 1, mid + 1, r, pos, x);
//		cout << "    end" << endl; 
	}
	long long Query(int now, int l, int r, int L, int R, int x){
//		cout << "Query:" << now << " " << l << " " << r << " " << L << " " << R << " " << x << endl;
		if (L > R) return 0;
		if (l == L && r == R) return T[now].Query(x);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R, x);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R, x);
		return Query(now << 1, l, mid, L, mid, x) + Query(now << 1 | 1, mid + 1, r, mid + 1, R, x);
	}
}seg;

int a[100010];

int main(){
	int n, m; scanf("%d%d", &n, &m);
	seg.Build(1, 1, 2 * m);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	long long sum = 0;
	for (int i = 1; i < n; i++){
		seg.Update(1, 1, 2 * m, a[i - 1], a[i] < a[i - 1] ? a[i] + m : a[i]);
		sum += a[i] > a[i - 1] ? a[i] - a[i - 1] : a[i] + m - a[i - 1];
	}
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= m; i++){
		long long val = sum - seg.Query(1, 1, 2 * m, 1, i - 1, i) - seg.Query(1, 1, 2 * m, 1, i + m - 1, i + m);
//		cout << "i:" << i << " " << val << endl;
		ans = min(ans, val);
	}
	printf("%lld\n", ans);
	return 0;
}
