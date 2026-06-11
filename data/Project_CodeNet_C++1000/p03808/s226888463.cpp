#include<bits/stdc++.h>

using namespace std;

#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

long long n,a[100005],ret=0,m,maks,idx,cnt,b[100005];
bool flag=1;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    if(n==1) {
    	cout<<"YES"<<endl;
    	return 0;
	}
    m=(n*(n+1))/2;
    for(long long i=0;i<n;i++) {
    	cin>>a[i];
    	ret=ret+a[i];
	}
	if(ret%m!=0) {
		cout<<"NO"<<endl;
		return 0;
	}
	cnt=ret/m;
	for(int i=0;i<n;i++) {
		b[i]=(a[(i+1)%n]-a[i]-cnt);
	}
	for(long long i=0;i<n;i++) {
		if(b[i]>0 || abs(b[i])%n!=0) {
			flag=0;
			break;
		}
	}
	if(!flag) {
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
	}
}