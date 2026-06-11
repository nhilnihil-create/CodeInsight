#include<stdio.h>
#include<string.h>

int main(void){
	char s[100000];
	int l;
	int i,j;
	int n[26] = {};
	int th;
	int num;



	scanf("%s",s);
	
	l = strlen(s);

	for(i=2;i<=2;i++){
		th = i / 2 + 1;

		for(j=0;j<26;j++){
			n[j] = 0;
		}

		for(j=0;j<i;j++){
			num = s[j] - 'a';
			n[num]++;
			if(n[num] >= th){
				printf("%d %d\n",1,i);
				return 0;
			}
		}

		for(j=i;j<l;j++){
			num = s[j-i] - 'a';
			n[num]--;
			num = s[j] - 'a';
			n[num]++;
			if(n[num] >= th){
				printf("%d %d\n",j-i+2,j+1);
				return 0;
			}

		}
	}
	if(l > 2){
		for(i=3;i<=3;i+=2){
			th = i / 2 + 1;

			for(j=0;j<26;j++){
				n[j] = 0;
			}

			for(j=0;j<i;j++){
				num = s[j] - 'a';
				n[num]++;
				if(n[num] >= th){
					printf("%d %d\n",1,i);
					return 0;
				}
			}

			for(j=i;j<l;j++){
				num = s[j-i] - 'a';
				n[num]--;
				num = s[j] - 'a';
				n[num]++;
				if(n[num] >= th){
					printf("%d %d\n",j-i+2,j+1);
					return 0;
				}

			}
		}
	}



	printf("-1 -1\n");

	return 0;

}