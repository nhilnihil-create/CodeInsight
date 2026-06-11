#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fw(p) for(int w=0;w<(p);w++)
#define fx(p) for(int x=0;x<(p);x++)
#define fy(p) for(int y=0;y<(p);y++)
#define fz(p) for(int z=0;z<(p);z++)
#define fyg(p,g) for(int y=(g);y<(p);y++)
#define fzg(p,g) for(int z=(g);z<(p);z++)
#define ce(d) cout<<d<<endl;
#define vecp(p) int aa;cin>>aa;(p).push_back(aa);
#define vecpl(p) long long aa;cin>>aa;(p).push_back(aa);
#define vecps(p) string aa;cin>>aa;(p).push_back(aa);
#define vecp2(p) cin>>aa;(p).push_back(aa);
#define vecpl2(p) long long a	b;cin>>ab;(p).push_back(ab);
#define vecps2(p) string ab;cin>>ab;(p).push_back(ab);
#define set0(k,n) for(int nn=0;nn<(n);nn++){ (k).push_back(0); }
#define sorts(c) sort((c).begin(),(c).end());
#define reverses(c) reverse((c).begin(),(c).end());
#define vec(b) vector<int> (b);
#define vecl(b) vector<long long> (b);
#define vecs(b) vector<string> (b);
#define vecsize(b,size) vector<int> (b)((size));
#define pb(b,a) (b).push_back((a));
#define doublece(a,b) cout<<(a)<<' '<<(b)<<endl;
#define pairs(s) vector<pair<int,int>> (s);
#define pairsl(s) vector<pair<ll,ll>> (s);
#define pairss(s) vector<pair<string,string>> (s);
#define pairsp(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define pairspl(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define pairsps(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define pairsREV(s) (s).push_back(make_pair(bb,aa));
#define pairslREV(s) (s).push_back(make_pair(bb,aa));
#define pairssREV(s) (s).push_back(make_pair(bb,aa));
#define MOD 1000000007

int main()
{
	int N;
	cin >> N;
	vecl(A);
	vecl(B);
	fx(N) {
		vecpl(A);
	}
	fx(N) {
		vecpl(B);
	}

	if (A[N-1]!=B[0]) {
		ce(0)
		return 0;
	}

	ll ans = 1;
	fyg(N-1,1) {
		if (A[y-1]==A[y]&&B[y]==B[y+1]) {
			ans *= min(A[y],B[y]);
			ans %= MOD;
		}
	}
	fx(N-1) {
		if (A[x]!=A[x+1]) {
			if (x+2<N) {
				if (A[x+1]>B[x+2]&&B[x+1]!=A[x+1]) {
					ans = 0;
				}
			}
			else {
				if (B[x + 1] != A[x + 1]) {
					ans = 0;
				}
			}
		}
		if (B[x]!=B[x+1]) {
			if (x - 1 >= 0) {
				if (A[x - 1] < B[x] && B[x] != A[x]) {
					ans = 0;
				}
			}
			else {
				if (B[x] != A[x]) {
					ans = 0;
				}
			}
		}
	}
	ce(ans)
    return 0;
}

