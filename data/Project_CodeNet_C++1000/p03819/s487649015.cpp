/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
typedef long long ll;
inline void Fail(){printf("0");exit(0);}

const int maxn=300005;
int n,m,pos=1;
pii itv[maxn];

class BIT{
public:
	int t[maxn];
	void add(int v,int val){for(;v<=m;v+=(v&-v))t[v]+=val;}
	int qry(int v){
		int res=0;
		for(;v;v-=(v&-v))res+=t[v];
		return res;
	}
}T;

bool cmp(pii a,pii b){return a.snd-a.fst<b.snd-b.fst;}
 
int main(){
	scanf("%d%d",&n,&m);
	REP(i,n)scanf("%d%d",&itv[i].fst,&itv[i].snd);
	sort(itv+1,itv+1+n,cmp);
	REP(i,m){
		while(pos<=n&&itv[pos].snd-itv[pos].fst+1<i){
			T.add(itv[pos].fst,1);
			T.add(itv[pos].snd+1,-1);
			pos++;
		}
		int ans=n-pos+1;
//		cout<<ans<<endl;
		for(int j=i;j<=m;j+=i)ans+=T.qry(j);//,cout<<j<<" "<<T.qry(j)<<endl;
		printf("%d\n",ans);
	}
	return 0;
}

/*
Input:
-----------------
Output:
*/