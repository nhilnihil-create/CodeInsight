#include "bits/stdc++.h"
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define ins insert
#define ph push
#define f first
#define s second
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define btinpct(x) __builtin_popcountll((x))
mt19937 rng(8);    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return (rng() % (y+1-x)) + x; } //inclusivesss
string to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?b:gcd(b%a,a); }

#define ll long long int 
#define ld long double
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
typedef pair <ll, ll> pi; typedef pair <ll, pi> spi; typedef pair <pi, pi> dpi;

#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
// #define cerr if(0)cout
#define MAXN (200006)
ll n, k, A[MAXN];
struct node {
	pi key;
	ll prior, sz;
	node *l, *r;
	node(pi _key) {
		key=_key, prior=rand(0, 1e18), sz=1, l=r=0;
	}
}; typedef node* pnode;
ll inline cnt(pnode t) {return t?t->sz:0;}
void split(pnode t, pnode &l, pnode &r, pi key) {
	if(!t) return void(l=r=0);
	if(t->key <= key)
		split(t->r, t->r, r, key), l=t;
	else
		split(t->l, l, t->l, key), r=t;
	if(l) l->sz = cnt(l->l) + cnt(l->r) + 1;
	if(r) r->sz = cnt(r->l) + cnt(r->r) + 1;
}
void insert(pnode &t, pnode k) {
	if(!t) return void(t=k);
	if(t->prior > k->prior) {
		if(t->key > k->key) insert(t->l, k);
		else insert(t->r, k);
	} else {
		if(t->key > k->key) {
			split(t->l, k->l, t->l, k->key);
			t->sz = cnt(t->l) + cnt(t->r) + 1;
			k->r = t;
			t = k;
		} else {
			split(t->r, t->r, k->r, k->key);
			t->sz = cnt(t->l) + cnt(t->r) + 1;
			k->l=t;
			t=k;
		}
	}
	t->sz = cnt(t->l) + cnt(t->r) + 1;
}
ll query(pnode t, pi key) {
	if(!t) return 0;
	if(t->key <= key)
		return cnt(t->l) + 1 + query(t->r, key);
	else
		return query(t->l, key);
}
/*
	ans += query(treap, pi(sum-i*k, LLINF));
	insert(treap, new node(pi(sum-i*k, co++)));
*/ 
int main()
{
	FAST
	cin>>n>>k;
	FOR(i,1,n) cin>>A[i];
	ll sum = 0, ans = 0, co = 0;
	pnode treap; treap=new node(pi(0, co++));
	FOR(i,1,n) {
		sum += A[i];
		ans += query(treap, pi(sum-i*k, LLINF));
		insert(treap, new node(pi(sum-i*k, co++)));
	}
	cout<<ans<<'\n';
}
