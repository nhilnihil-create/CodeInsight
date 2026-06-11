#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int b[110000];
long long rem[110000];
char c[110000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",b+i);
		if(i<a-1)scanf("%s",c+i);
	}
	long long tmp=0;
	for(int i=a-1;i>=0;i--){
		tmp+=b[i];
		rem[i]=tmp;
	}
	long long ret=-inf;
	long long cur=b[0];
	bool flag=true;
	for(int i=0;i<a-1;i++){
		if(c[i]=='-'){
			flag=false;
			int len=0;
			long long val=-b[i+1];
			for(int j=i+1;j<a-1;j++){
				if(c[j]=='+')len++;
				else break;
				val-=b[j+1];
			}
			if(len==0){
				ret=max(ret,cur-b[i+1]+rem[i+2]);break;
			}
			ret=max(ret,cur+val+rem[i+len+2]);
			cur-=b[i+1];
			for(int j=i+1;j<a-1;j++){
				if(c[j]=='+')len++;
				else break;
				cur+=b[j+1];
			}
			
		}else if(flag){
			cur+=b[i+1];
		}
	}
	ret=max(ret,cur);
	printf("%lld\n",ret);
}
