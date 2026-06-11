#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define Fst first
#define Snd second
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const LL mod = 1e9 + 7;
int N;
int x[100010];

int main(){
	scanf("%d" , &N);
	repp(i,0,N){
		scanf("%d" , x + i);
	}
	LL ans = 1;
	int p = 0;
	int q = 0;
	repp(i,0,N){
		while(p < N && x[p] > q * 2){
			++p;
			++q;
		}
		if(p < N && x[p] == q * 2) ++p;
		(ans *= (p-i)) %= mod;
	}
	printf("%lld\n" , ans);
	return 0;
}
