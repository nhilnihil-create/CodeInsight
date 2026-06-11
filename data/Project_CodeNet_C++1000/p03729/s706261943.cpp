#include<stdio.h>
int main(){
	char q[15];
	char w[15];
	char e[15];
	char r,t;
	scanf("%s %s %s",q,w,e);
	
	for(int i = 0; q[i]!= '\0';i++){
	r=q[i];
	}
	for(int i =0; w[i] != '\0'; i++){
		t =w[i];
	}
	if (r == w[0] && t ==e[0]){
		printf("YES");
	}
	else{
	printf ("NO");
	}
	return 0;
}

