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
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int x[110000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",x+i);
	long long ret=1;
	int at=0;
	for(int i=0;i<a;i++){
		while(at<a&&x[i]<i*2+1-at*2){
			ret=(ret*(i+1-at))%mod;
			at++;
		}
	}
	while(at<a){
		ret=(ret*(a-at))%mod;
		at++; 
	}
	printf("%lld\n",ret);
}