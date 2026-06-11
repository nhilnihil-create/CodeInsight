# include "algorithm"
# include "iostream"
# include "cstdio"
# define lowbit(x) (x&-x)

using namespace std;

const int maxm=3e5+10;

int N,M,Tree[maxm],Ans[maxm];

struct line{
	int L;
	int R;
	int Len;
	# define L(x) Line[x].L
	# define R(x) Line[x].R
	# define Len(x) Line[x].Len
}Line[maxm];

inline bool Comp(line x,line y){
	return x.Len<y.Len;
}

inline void Update(int x,int Value){
	while(x<=M){
		Tree[x]+=Value;
		x+=lowbit(x);
	}
	return;
}

inline int Ask(int x){
	register int Result=0;
	while(x){
		Result+=Tree[x];
		x-=lowbit(x);
	}
	return Result;
}

int main(){
	register int i,j,k,Add,Now;
	scanf("%d%d",&N,&M);
	Add=N;
	for(i=1;i<=N;i++){
		scanf("%d%d",&L(i),&R(i));
		Len(i)=R(i)-L(i)+1;
		Update(L(i),1);
		Update(R(i)+1,-1);
	}
	sort(Line+1,Line+1+N,Comp);
	for(i=M;i;i--){
		for(Add;Len(Add)>=i;Add--){
			Update(L(Add),-1);
			Update(R(Add)+1,1);
		}
		Now=N-Add;
		for(j=i;j<=M;j+=i){
			Now+=Ask(j);
		}
		Ans[i]=Now;
	}
	for(i=1;i<=M;i++){
		printf("%d\n",Ans[i]);
	}
	return 0;
}