#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

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
}T;

int a[100010];
long long res[200010];

int main(){
	int n, m; scanf("%d%d", &n, &m);
	T.init();
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	long long sum = 0;
	vector <pii> v;
	for (int i = 1; i < n; i++){
		sum += a[i] > a[i - 1] ? a[i] - a[i - 1] : a[i] + m - a[i - 1];
		v.push_back(mp(a[i - 1], a[i] < a[i - 1] ? a[i] + m : a[i]));
	}
	sort(v.begin(), v.end());
	int pos = 0;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= 2 * m; i++){
		while (pos < v.size() && v[pos].fi < i){
			T.Insert(v[pos].se, v[pos].fi), pos++;
		}
		res[i] = T.Query(i);
	}
	for (int i = 1; i <= m; i++){
		ans = min(ans, sum - res[i] - res[i + m]);
	}
	printf("%lld\n", ans);
	return 0;
}
