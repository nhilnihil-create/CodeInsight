#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

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
#define repv(t,it,v) for(vector<t>::iterator it = v.begin() ; it != v.end() ; ++it)

typedef long long LL;

int N;
int A[100010];

int gcd(int a , int b){
	return b > 0 ? gcd(b,a%b) : a;
}

int main(){
	scanf("%d" , &N);
	int p = 0;
	LL s = 0;
	repp(i,0,N){
		scanf("%d" , A + i);
		s += A[i] - 1;
		if(A[i] == 1) ++p;
		if(A[i] % 2 == 1) ++p;
	}
	if(s % 2 == 1 || p != 1){
		printf("%s\n" , s % 2 == 1 ? "First" : "Second");
		return 0;
	}
	int t = 0;
	while(p == 1 && s % 2 == 0){
		p = 0;
		s = 0;
		if(A[0] % 2 == 1) --A[0];
		int g = A[0];
		repp(i,1,N){
			if(A[i] % 2 == 1) --A[i];
			g = gcd(g,A[i]);
		}
		repp(i,0,N){
			A[i] /= g;
			if(A[i] == 1) ++p;
			if(A[i] % 2 == 1) ++p;
			s += A[i] - 1;
		}
		++t;
	}
	printf("%s\n" , (s+t) % 2 == 1 ? "First" : "Second");
	return 0;
}
