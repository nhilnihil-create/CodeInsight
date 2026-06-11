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
char str[1100][1100];
char wolf[6]="RGBY";

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(c%2){
		for(int i=0;i<a;i++)for(int j=0;j<b;j++)str[i][j]=wolf[(i+j)%2];
	}else{
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				int X=(i+j);
				int Y=(i-j)+10000;
				int cl=0;
				if(X/2/(c/2)%2)cl++;
				if(Y/2/(c/2)%2)cl+=2;
				str[i][j]=wolf[cl];
			}
		}
	}
	for(int i=0;i<a;i++)printf("%s\n",str[i]);
}