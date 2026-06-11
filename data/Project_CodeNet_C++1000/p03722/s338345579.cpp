
#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<random>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>
#include<boost/multiprecision/cpp_int.hpp>


using namespace std;
using namespace boost::multiprecision;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldb = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
template<typename A, typename B>
void mins(A & a, const B & b) { a = min(a, (A)b); };
template<typename A, typename B>
void maxs(A & a, const B & b) { a = max(a, (A)b); };

struct edge {
	int from, to;
	ll cost;
};

struct node {
	ll dist;
	bool flag;
	vector<int> edto;
	vector<int> edfrom;
};

void f(vector<node>& nod, vector<edge>& ed, int ind) {
	nod[ind].flag = true;
	for (int e : nod[ind].edfrom) if (!nod[ed[e].from].flag) f(nod, ed, ed[e].from);
}

int main() {
	ll inf = 1e18;
	ll N, M; cin >> N >> M;
	vector<edge> ed(M);
	vector<node> nod(N);
	REP(i, 0, M) {
		cin >> ed[i].from >> ed[i].to >> ed[i].cost;
		ed[i].from--;
		ed[i].to--;
		ed[i].cost *= -1;
		nod[ed[i].from].edto.push_back(i);
		nod[ed[i].to].edfrom.push_back(i);
	}
	REP(i, 0, N) {
		nod[i].dist = i == 0 ? 0 : inf;
		nod[i].flag = false;
	}
	f(nod, ed, N - 1);
	REP(i, 0, N) {
		REP(j, 0, M) {
			edge& e = ed[j];
			if (nod[e.to].dist > nod[e.from].dist + e.cost) {
				nod[e.to].dist = nod[e.from].dist + e.cost;
				if (i == N - 1 && nod[e.to].flag) {
					PRI("inf");
					return 0;
				}
			}
		}
	}
	PRI(-nod[N - 1].dist);
	return 0;
}