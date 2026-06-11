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
#define sorts(c) sort((c).begin(),(c).end());
#define reverses(c) reverse((c).begin(),(c).end());
#define vec(b) vector<int> (b);
#define vecl(b) vector<long long> (b);
#define vecs(b) vector<string> (b);
#define pb(b,a) (b).push_back((a));
#define doublece(a,b) cout<<(a)<<' '<<(b)<<endl;
#define pairs(s) vector<pair<int,int>> (s);
#define pairsp(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define MOD 1000000007
#define cey ce("Yes")
#define cen ce("No")
#define ceY ce("YES")
#define ceN ce("NO")

int main()
{
		int N, X;
	cin >> N>>X;
	if (X==1||X==N*2-1) {
		cen;
		return 0;
	}

	cey;
	if (X==2) {
		if (N==2) {
			fx(3) {
				ce(x+1)
			}
		}
		else {
			int i = 0;
		int j = 0;
		for (int x = 5; x <= 2 * N - 1 && i < N-2; x++) {
			i++;
			j = x;
			ce(x)
		}
		ce(4)
			ce(1)
			ce(2)
			ce(3)
			i = j+1;
		while (i <= 2 * N - 1) {
			ce(i++)
		}
		}
	}
	else {
		int i = 0;
		int j = 0;
		for (int x = 1; x <= 2 * N - 1 && i < N-2; x++) {
			if (x == X || x == X - 1 || x == X - 2 || x == X + 1) { continue; }
			i++;
			j = x;
			ce(x)
		}
		ce(X - 1)
			ce(X)
			ce(X + 1)
			ce(X - 2)
			i = j+1;
		while (i <= 2 * N - 1) {
          if (i == X || i == X - 1 || i == X - 2 || i == X + 1) {i++; continue; }
			ce(i++)
		}
	}
    return 0;
}

