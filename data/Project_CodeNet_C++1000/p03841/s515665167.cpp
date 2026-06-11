#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define sz(x) (int)(x.size())
#define fr(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
////////////////////////

int const N = 541;
int const M = N * N;

int n, ans[M], cnt[N], x[N], g[M];
vector<pii> a;

void bad(){
	cout << "No" << endl;
	exit(0);
}

void print(){
	cout << "Yes" << endl;
	fr(i, 0, n*n){
		cout << ans[i] << " ";
	}
}

void tryPlace(int p, int v){
	if(p >= n * n) bad();
	if(ans[p] != 0) bad();
	ans[p] = v;
	++cnt[v];
}

void solve(){
	cin >> n;
	fr(i, 0, n){
		cin >> x[i];
		--x[i];
		g[x[i]] = 1;
		tryPlace(x[i], i+1);
		a.pb(mp(x[i], i+1));
	}

	sort(a.begin(), a.end());
	int p = 0;
	fr(i, 0, n){
		int rem = a[i].second - 1;
		while(rem > 0){
			--rem;
			while(ans[p] != 0) ++p;
			if(p > a[i].first) bad();
			tryPlace(p, a[i].second);
		}
	}
	vector<int> st;
	p = 0;
	while(p < n * n){
		if(ans[p] == 0){
			if(sz(st) == 0) bad();
			tryPlace(p, st.back());
			if(cnt[st.back()] == n) st.pop_back();
		}else{
			if(g[p] && cnt[ans[p]] < n) st.pb(ans[p]);
		}
		++p;
	}
	fr(i, 1, n+1) if(cnt[i] != n) bad();
	print();
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();


	return 0;
}