#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
char str[110];
char in[10];
int main(){
	for(int i=0;i<10;i++){
		int left=-1;
		if(i==0)left++;
		int right=10;
		while(left+1<right){
			int M=(left+right)/2;
			str[i]=M+'0';
			for(int j=i+1;j<13;j++)str[j]='9';
			str[13]=0;
			printf("? %s\n",str);fflush(stdout);scanf("%s",in);
			if(in[0]=='Y'){
				right=M;
			}else{
				left=M;
			}
		}
		str[i]=right+'0';
	}
	str[10]=0;
	long long b;
	sscanf(str,"%lld",&b);
	for(int i=9;i>=0;i--){
		if(b%10==9){
			b--;
			printf("? %lld\n",b*10);fflush(stdout);scanf("%s",in);
			if(in[0]=='Y'){
				printf("! ");
				for(int j=0;j<=i+1;j++)printf("%c",str[j]);
					printf("\n");
				return 0;
			}
			b++;
		}else{
			b++;
			printf("? %lld\n",b);fflush(stdout);scanf("%s",in);
			if(in[0]=='N'){
				printf("! ");
				for(int j=0;j<=i+1;j++)printf("%c",str[j]);
					printf("\n");
				return 0;
			}
			b--;
		}
		b/=10;
	}

	printf("! %c\n",str[0]);
}