#include<stdio.h>
#include<string.h>
int main(){
	int m,n,p,f=0,i,j;
	scanf("%d %d",&m,&n);
	char l;
	char s[m][n][5], s1[8];
	strcpy(s1,"snuke");
	for( i=0;i<m;i++){
		for( j=0;j<n;j++){
			scanf("%s",s[i][j]);
			if(f==0){
				int k;
				for( k=0;k<5;k++){
					if(s[i][j][k]!=s1[k]){
							break;
					}
				}
				if(k==5){
					f=1;
					p = i;
					l = j;
				}
			}
		}
	}
	printf("%c%d\n",l+65,p+1);
	return 0;
}