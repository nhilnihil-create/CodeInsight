#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <iomanip>
#include <complex>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define SIZE 100005

using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
long long int MOD = 1000000007;
int aa[SIZE];
int pos[SIZE];
bool used[SIZE];
int anspos[SIZE];
int cyc[SIZE];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&aa[i]);
	for(int i=0;i<n-1;i++)pos[i]=i;
	int M;ll K;
	scanf("%d %lld",&M,&K);
	for(int i=0;i<M;i++){
		int hoge;
		scanf("%d",&hoge);hoge--;
		swap(pos[hoge],pos[hoge-1]);
	}
	
	for(int i=0;i<n-1;i++){//posの移動
		if(!used[i]){//同じサイクルに属するものをすべてチェック
			int wh=i;
			int len=0;
			bool flag=true;
			while(flag){
				used[wh]=true;
				cyc[len]=wh;
				wh=pos[wh];
				len++;
				if(wh==i)flag=false;
			}
			//cout<<len<<endl;
			for(int j=0;j<len;j++){
				int nex=(int)(K%len);
				anspos[cyc[j]]=cyc[(nex+j)%(len)];
			}
		}
	}
	ll sum=aa[0];
	//for(int i=0;i<n-1;i++)printf("%d ",anspos[i]);
	//cout<<endl;
	for(int i=0;i<n;i++){
		printf("%lld\n",sum);
		int now=anspos[i];
		sum=sum+aa[now+1]-aa[now];
	}
}