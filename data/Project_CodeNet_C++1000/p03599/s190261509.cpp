#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
	A *= 100;
	B *= 100;

	double per{-1};
	ll resw{0}, ress{0};


	REP(w, F+1)
	{
		REP(s, F+1)
		{
			if (w + s > F)
				continue;

			if (s*(100+E) > E*(w+s))
				continue;
			double tmp = 100*s/(double)(w+s);

			bool oks{false};
			bool okw{false};
			
			
			// can water
			ll N = w / A;
			for (ll a = 0; a <= N; ++a)
			{
				if ((w - A*a) % B == 0)
					okw = true;
			}
			
			// can suger
			N = s / C;
			for (ll c = 0; c <= N; ++c)
			{
				if ((s - C*c) % D == 0)
					oks = true;
			}

			if (oks && okw && per < tmp)
			{
				per = tmp;
				resw = w;
				ress = s;
			}
		}
	}

	std::cout << resw+ress << " " << ress << std::endl;
	// std::cout << "per : " << per << std::endl;
}
