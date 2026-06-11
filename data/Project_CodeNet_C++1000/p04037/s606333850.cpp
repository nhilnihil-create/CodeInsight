#include<cstdio>
#include<algorithm>
using namespace std;
int N,A[100010];
bool Cmp(const int &X,const int &Y){
	return X>Y;
}
int main(){
	scanf("%d",&N);
    for(int i=1;i<=N;i++){
    	scanf("%d",&A[i]);
	}
    sort(A+1,A+N+1,Cmp);
    /*
    for(int i=1;i<=N;i++){
    	printf("%d ",A[i]);
	}
	printf("\n");
	*/
    for(int i=1;i<=N;i++){
        if(i+1>A[i+1]){
            int Ans=0;
            for(int j=i+1;A[j]==i;j++){
            	Ans=Ans^1;
			}
            Ans=Ans|((A[i]-i)&1);
            if(Ans){
            	printf("First\n");
			}else{
				printf("Second\n");
			}
            return 0;
        }
    }
}