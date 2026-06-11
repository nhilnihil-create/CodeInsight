#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
int A[100010];

bool check(){
	int s = 0;
	int c = 0;
	bool o = 0;
	FWD(i,0,n){
		if(A[i] == 1) o = 1;
		if((A[i]-1)&1)
			s = 1-s;
		else
			++c;
	}
	if(o) return s;
	if(s) return 1;
	if(c != 1) return 0;
	FWD(i,0,n) if(A[i]&1) --A[i];
	int g = A[0];
	FWD(i,1,n) g = gcd(g, A[i]);
	FWD(i,0,n) A[i] /= g;
	return !check();
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		scanf("%d", &A[i]);
	}
	printf(check()?"First\n":"Second\n");
	return 0;
}
