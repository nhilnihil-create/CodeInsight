#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <functional>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cassert>

#ifdef DEBUG
#include "library/Utility/debug.cpp"
#else
#define debug(...)
#endif

#define rep(i,n) for(int i=0;i<(n);++i)
#define EL '\n'
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
using lnt = long long;
constexpr lnt INF = 2e18;
/*-*/

struct P
{
	int x,y,c;
	P(int x, int y, int c) : x(x),y(y),c(c) {}
};

int main() {
	int h,w,d;
	std::cin >> h >> w >> d;
	std::vector<std::vector<int> > g(2*h+d,std::vector<int>(2*w+d,-1));
	auto dec = [] (int c) -> char {
		if(c==0) return 'R';
		if(c==1) return 'Y';
		if(c==2) return 'G';
		if(c==3) return 'B';
		return 'x';
	};
	if(d&1) {
		rep(i,h) rep(j,w) {
			g[i][j] = (i%2)*2+(j%2);
		}
		rep(i,h) {
			rep(j,w) std::cout << dec(g[i][j]);
			std::cout << EL;
		}
	} else {
		std::queue<P> que;
		for(int i=0;i*d<2*h+d;i++) {
			for(int j=0;j*d<2*w+d;j++) {
				int c = (i%2)^(j%2);
				g[i*d][j*d] = c;
				que.emplace(i*d,j*d,c);
				if(i*d+1<2*h+d) {
					g[i*d+1][j*d] = c;
					que.emplace(i*d+1,j*d,c);
				}
			}
		}
		for(int i=0;i*d+d/2<2*h+d;i++) {
			for(int j=0;j*d+d/2<2*w+d;j++) {
				int c = (i%2)^(j%2)+2;
				g[i*d+d/2][j*d+d/2] = c;
				que.emplace(i*d+d/2,j*d+d/2,c);
				if(i*d+1+d/2<2*h+d) {
					g[(i*d+1+d/2)][j*d+d/2] = c;
					que.emplace((i*d+1+d/2),j*d+d/2,c);
				}
			}
		}
		while(!que.empty()) {
			auto p = que.front(); que.pop();
			int x=p.x,y=p.y,c=p.c;
			for(int dx=-1;dx<=1;dx++) {
				for(int dy=-1;dy<=1;dy++) {
					if(dx*dy!=0) continue;
					if(dx==0&&dy==0) continue;
					if(dx+x<0||dx+x>=2*h+d) continue;
					if(dy+y<0||dy+y>=2*w+d) continue;
					if(g[dx+x][dy+y]!=-1) continue;
					g[dx+x][dy+y]=c;
					que.emplace(dx+x,dy+y,c);
				}
			}
		}
		rep(i,h) {
			rep(j,w) std::cout << dec(g[i+d][j+d]);
			std::cout << EL;
		}
	}
}
