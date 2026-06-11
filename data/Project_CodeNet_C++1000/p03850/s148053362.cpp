#include <cstdio>

const int MAXN=100011;
const long long LONF=4567891012345678910LL;


int N;
int A[MAXN];
int O[MAXN];

long long F[MAXN][3];

int rO(){
	static char ch[2];
	scanf("%s", ch);
	return ch[0]=='+';
}

void relax(long long &f, long long v){
	if(f<v)	f=v;
}

int Calc(int t, int o, int a){
	if(t)	o=!o;
	return ((o<<1)-1)*a;
}

int main(){
	
	scanf("%d", &N);
	
	scanf("%d", &A[1]);
	for(int i=2;i<=N;++i){
		O[i]=rO();
		scanf("%d", &A[i]);
	}
	
	for(int i=1;i<=N;++i)
		for(int j=0;j<=2;++j)
			F[i][j]=-LONF;
	
	F[1][0]=(long long)(A[1]);
	for(int i=2;i<=N;++i){
		for(int j=0;j<3;++j){
			for(int k=0;k<=j;++k){
				relax(F[i][k], F[i-1][j]+Calc(k&1, O[i], A[i]));
			}
			if(!O[i]){
				for(int k=0;k<=j && k<2;++k){
					relax(F[i][k+1], F[i-1][j]+Calc(k&1, O[i], A[i]));
				}
			}
		}
	}
	
	long long Ans=-LONF;
	for(int j=0;j<3;++j)
		relax(Ans, F[N][j]);
	printf("%lld\n", Ans);
	
	return 0;
}