#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
const int inf = INT_MAX / 2; const ll INF = LLONG_MAX / 2;
//template end

int bit[100010]={};
void add(int i,int x){
	while(i<100010)bit[i]+=x,i+=(i&-i);
}
int sum(int i){
	int res=0;
	while(i)res+=bit[i],i-=(i&-i);
  return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<P> range(n);
	rep(i,0,n){
		int l,r; scanf("%d%d",&l,&r);
		range[i]={r-l+1,l};
	}
	sort(ALL(range)); int ans,pre=0,idx;
	rep(i,1,m+1){
		if(i==1){
			printf("%d\n",n); continue;
		}
		idx=lower_bound(ALL(range),P{i,-1})-range.begin();
		ans=n-idx;
		rep(j,pre,idx){
			add(range[j].second,1);
			add(range[j].first+range[j].second,-1);
		}
		rep(j,1,m/i+1)ans+=sum(j*i);
		printf("%d\n",ans); pre=idx;
	}
}