# include "iostream"
# include "cstdio"
# include "vector"
# define lowbit(x) (x&-x)

using namespace std;

const int maxm=3e5+10;

int N,M,Tree[maxm<<1],Ans[maxm];
vector<int> L[maxm],H[maxm];

inline void Update(int x,int Value){
	while(x<=M){
		Tree[x]+=Value;
		x+=lowbit(x);
	}
	return;
}

inline int Ask(int x){
	if(x>M) return 0;
	register int Result=0;
	while(x){
		Result+=Tree[x];
		x-=lowbit(x);
	}
	return Result;
}

int main(){
	register int i,j;
	int x,y;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++){
		scanf("%d%d",&x,&y);
		L[x].push_back(y);
	}
	for(i=1;i<=M;i++){
		for(j=i;j<=M;j+=i){
			H[j].push_back(i);
		}
	}
	for(i=1;i<=M;i++){
		for(j=0;j<L[i].size();j++){
			Update(i,1);
			Update(L[i][j]+1,-1);
		}
		for(j=0;j<H[i].size();j++){
			Ans[H[i][j]]+=Ask(i)-Ask(i+H[i][j]);
		}
	}
	for(i=1;i<=M;i++){
		printf("%d\n",Ans[i]);
	}
	return 0;
}