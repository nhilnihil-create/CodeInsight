#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
/////////////////////

int const N = 1e5 + 41;

int n, a[N];
vector<pii> b;

void pushb(){
	sort(a, a+n);
	reverse(a, a+n);
	int q = 1;
	fi(1, n){
		if(a[i] != a[i-1]){
			b.pb(mp(a[i-1], q));
			q = 1;
		}else{
			++q;
		}
	}
	b.pb(mp(a[n-1], q));
}

void solve(){
	pushb();
	int w = 0;
	priority_queue<ll, vector<ll>, greater<ll> > t;
	ll add = 0;
	int q = b[0].second;
	fi(1, sz(b)){
		int h = b[i-1].first - b[i].first;
		add += h;
		w = (h % 2 == 0 ? 0 : 1);
		int w0 = (b[i].second % 2 == 1 ? 0 : 1);
		if(w == 1 && w0 == 0 || w == 0 && w0 == 1){
			//nothing
		}else{
			if(w == 1){
				t.push(q + add);
			}else{
				t.push(q - 1 + add);
			}
		}
		w = 0;
		q += b[i].second;
	}
	if(b.back().first != 1){
		w = ((b.back().first - 1) % 2 == 0 ? 0 : 1);
		add += b.back().first - 1;
	}
	while(sz(t)){
		ll x = t.top();
		if(x - add < 0){
			t.pop();
		}else break;
	}
	if(sz(t) == 0){
		if(w){
			if( (n - 1) % 2 == 0){
				printf("First\n");
			}else{
				printf("Second\n");
			}
		}else{
			if( (n - 1) % 2 == 1){
				printf("First\n");
			}else{
				printf("Second\n");
			}
		}
	}else{
		ll x = t.top() - add;
		--x;
		x = max(x, 0LL);
		if(x % 2 == 0){
			printf("First\n");
		}else{
			printf("Second\n");
		}
	}
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d",&n);
	fi(0, n) scanf("%d",&a[i]);

	solve();



	return 0;
}