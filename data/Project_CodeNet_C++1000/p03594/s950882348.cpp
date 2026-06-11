#include <bits/stdc++.h>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pr pair<int,int>
#define SZ(S) int(S.size())
#define REP(i,a,b) for(int i=a;i<b;++i)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,b,a) for(int i=b;i>=a;--i)
#define CLR(A,x) memset(A,x,sizeof(A))
#define ALL(S) S.begin(),S.end()

#define OUT(a,l,r) cout<<#a": ";FOR(i,l,r)cout<<a[i]<<" ";cout<<endl
#define PRT(a) cout<<"--> "#a" "<<a<<endl

using namespace std;
typedef long long ll;

const int N=1005,INF=0x3f3f3f3f;
const ll P=1e9+7;

template<typename T>
inline void read(T& x,int f=1,char s=getchar()) {
	for(x=0;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1; 
	while(s<='9'&&s>='0') x=x*10+s-'0',s=getchar();x*=f;
}

char s[4]={'R','Y','G','B'};

int get(int x,int y,int k) {
	x+=1000*k,y+=1000*k;
	return ((((x-1)/k)&1)<<1)+(((y-1)/k)&1);
}

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	if(k&1) {
		FOR(i,1,n) FOR(j,1,m) {
			putchar(s[(i+j)&1]);
			if(j==m) putchar('\n');
		}
	}
	else {
		k/=2;
		FOR(i,1,n) {
			FOR(j,1,m) {
				if((i+j)&1)cout<<s[get((i-j+1)/2,(i+j-1)/2,k)];
				else cout<<s[get((i-j)/2,(i+j)/2,k)];
			}
			cout<<endl;
		}
	}
	return 0;
}