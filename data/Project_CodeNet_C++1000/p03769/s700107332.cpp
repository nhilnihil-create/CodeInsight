#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <stack>
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

LL N;;
deque<int> Q;
int a[111];
int m;

int main(){
	scanf("%lld" , &N);
	++N;
	while(N > 1){
		if(N % 2 == 0){
			++a[m];
			N /= 2;
		} else {
			++m;
			--N;
		}
	}
	int z = 0;
	repm(i,m,-1){
		repp(j,0,a[i]){
			Q.push_back(++z);
		}
		if(i != 0) Q.push_front(++z);
	}
	printf("%d\n" , z * 2);
	while(!Q.empty()){
		printf("%d " , Q.front());
		Q.pop_front();
	}
	repp(i,1,z+1){
		printf("%d%c" , i , i == z ? '\n' : ' ');
	}
	return 0;
}
