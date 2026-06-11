//  LINK ZADATKA: http://code-festival-2017-quala.contest.atcoder.jp/tasks/code_festival_2017_quala_d

#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
#include <fstream>
#include <cstring>
#include <string>
#include <climits>

using namespace std;

typedef long long ll;
typedef complex<double> point;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define FOR(k,a,b) for(int k=(a); k<=(b); ++k)
#define REP(k,a) for(int k=0; k<(a);++k)
#define SZ(a) int((a).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define MP make_pair
#define INF 999999999
#define INFLONG 1000000000000000000
#define MOD 1000000007
#define MAX 100
#define ITERS 100
#define MAXM 200000
#define MAXN 1000000
#define _gcd __gcd
#define eps 1e-9

int n, m,k; char sol[550][550];
int main(){
	
	sd(n); sd(m);

	sd(k);
	int zbr, oduz;
	
	/*REP(i, n){
		REP(j, m){
			printf("%d %d  ", i+j, i-j);
		}
		printf("\n");
	}*/
	
	REP(i, n){
		REP(j, m){	
			zbr = i+j;
			oduz = i-j;
			zbr += MAXN;
			zbr /= k;
			oduz += MAXN;
			oduz /= k;
			zbr %= 2; oduz %= 2;
			//printf("%d %d ", zbr, oduz);
			if(zbr == 0 && oduz == 0) sol[i][j] = 'R';
			if(zbr == 0 && oduz == 1) sol[i][j] = 'G';
			if(zbr == 1 && oduz == 0) sol[i][j] = 'Y';
			if(zbr == 1 && oduz == 1) sol[i][j] = 'B';
		}
		//printf("\n");
	}
	
	REP(i, n) printf("%s\n", sol[i]);
	return 0;
}
