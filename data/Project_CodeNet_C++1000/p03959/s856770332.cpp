#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
#include<iomanip>
#include<list>
#include<deque>
using namespace std;
//#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define END {}
#endif
typedef long long ll;
#define int ll
#define uset unordered_set
#define umap unordered_map
typedef std::pair<int,int> P;
struct edge{int to,cost;};
const int INF=100000000000000000;
const int INF2=9223372036854775807;
const int MOD=1000000007;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define min(X,Y) (((int)(X)<(int)(Y))?(X):(Y))
#define max(X,Y) (((int)(X)>(int)(Y))?(X):(Y))
#define MAX(X,Y) (*max_element(X,Y))
#define MIN(X,Y) (*min_element(X,Y))
#define NP(X,Y) next_permutation(X,Y)
#define setp(X,Y) cout<<fixed<<setprecision(Y)<<X;
int ceil2(int a,int b){if(a%b==0){return a/b;}else{return a/b+1;}}
int pow2(int a,int b){int r=1;for(int i=1;i<=b;i++){r*=a;}return r;}
int Log2(int a){int t=0;while(1){if(a==0||a==1){break;}a/=2;t++;}return t;}

int N;
int T[100010],A[100010];

signed main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>T[i];
	}
	for(int i=1;i<=N;i++){
		cin>>A[i];
	}
	int ans=1;
	for(int i=1;i<=N;i++){
		if((T[i-1]<T[i]&&A[i]<T[i]) || (A[i]>A[i+1]&&A[i]>T[i])){
			ans=0;
		}
		else if(A[i]==A[i+1]&&T[i]==T[i-1]){
			ans*=min(A[i],T[i]);
			ans%=MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}
