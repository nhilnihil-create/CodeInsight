#include<stdio.h>
const int maxn = 100005;

int main(){
//	freopen("b.txt","r",stdin);
	int a=0,b=0,c=0,n,x;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &x);
		if(x%4==0){
			c++;
		}else if(x%2==0){
			b++;
		}else{
			a++;
		}
	}
	if(b==0){
		if(a-1>c){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}else{
		if(a>c){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}

	return 0;
}