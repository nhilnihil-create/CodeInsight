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
int H, W;
	cin >> H >> W;

	map<char, int> K;
	fx(H) {
		fy(W) {
			char c;
			cin >> c;
			K[c]++;
		}
	}
	int div[3] = { 4,2,1 };
	int counts[3] = { 0,0,0 };
	fw(3) {
		fz(26) {
			counts[w] += K['a' + z] / div[w];
			K['a' + z] -= K['a' + z] / div[w] * div[w];
		}
	}

	if (H % 2 == 0 && W % 2 == 0) {
		if (counts[0] == H*W/4 ) {
			ce("Yes")
		}
		else {
			ce("No")
		}
	}
	else if (H % 2 == 1 && W % 2 == 1) {
		if (counts[2] == 1) {
			fx(counts[0]+1) {
				if (counts[1] + 2 * x == (H - 1) / 2 + (W - 1) / 2 && counts[0] - x == (H-1)*(W-1)/4) {
					ce("Yes")
						return 0;
				}
			}
			ce("No")
		}
		else {
			ce("No")
		}
	}
	else {
		if (H%2==0) {
			fx(counts[0]+1) {
				if (counts[0] - x == H / 2 * (W - 1) / 2 && counts[1] + 2 * x == H / 2) {
					ce("Yes")
						return 0;
				}
			}
			ce("No")
		}
		else {
			fx(counts[0]+1) {
				if (counts[0]-x==W/2*(H-1)/2&&counts[1]+2*x==W/2) {
					ce("Yes")
						return 0;
				}
			}
			ce("No")
		}
	}
    return 0;
}

