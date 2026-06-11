#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))
#define iter(v,ite) for(auto ite=(v).begin();ite!=(v).end();ite++)
#define mimunum(v,x) distance((v).begin(),lower_bound((v).begin(),(v).end(),x))


struct unifo{
	int n;
	int uni[200005];
	void init(int in){
		n=in;
		rep(i,n)uni[i]=i;
	}
	int find(int p){
		if(uni[p]==p)return p;
		else return (uni[p]=find(uni[p]));
	}
	void mer(int p,int q){
		if(!same(p,q))uni[find(p)]=find(q);
	}
	bool same(int p,int q){
		return find(p)==find(q);
	}
	void out(){
		vector<mp> ps;
		//printf("%d %d\n",i,find(i));
		rep(i,n)ps.push_back(mp(find(i),i));
		sort(ps.begin(),ps.end());
		printf("uni .. %d elem\n{ ",n);
		rep(i,n){
			if(i!=0 && ps[i-1].fir!=ps[i].fir)printf("}\n{ ");
			printf("%d ",ps[i].sec);
		}
		printf("}\n\n");
	}
} uni[2];


int n;
mp dat[200005];
int main(void){
	int ns[2];
	scanf("%d%d%d",&n,&ns[0],&ns[1]);
	rep(t,2){
		uni[t].init(n+5);
		rep(i,ns[t]){
			int a,b;
			scanf("%d%d",&a,&b); a--; b--;
			uni[t].mer(a,b);
		}
	}
	rep(i,n)dat[i]=mp(uni[0].find(i),uni[1].find(i));
	
	map<mp,int> mas;
	rep(i,n){
		mas[dat[i]]++;
	}
	rep(i,n){
		printf("%d\n",mas[dat[i]]);
	}
	
	return 0;
}




