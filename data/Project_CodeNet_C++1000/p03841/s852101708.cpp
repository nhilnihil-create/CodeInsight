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
int b[510];
pair<int,int>p[510];
int ret[300000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){scanf("%d",b+i);b[i]--;}
	for(int i=0;i<a;i++)p[i]=make_pair(b[i],i);
	std::sort(p,p+a);
	int at=0;
	for(int i=0;i<a;i++){
		int s=p[i].first;
		int t=p[i].second;
		int rem=t;
		while(at<s&&rem){
			if(!ret[at]){
				rem--;
				ret[at]=t+1;
			}
			at++;
		}
		if(rem){
			printf("No\n");return 0;
		}
		ret[s]=t+1;
	}
//	printf("A\n");
	at=a*a-1;
	for(int i=a-1;i>=0;i--){
		int s=p[i].first;
		int t=p[i].second;
		int rem=a-1-t;
		while(at>s&&rem){
			if(!ret[at]){
				rem--;
				ret[at]=t+1;
			}
			at--;
		}
		if(rem){
			printf("No\n");return 0;
		}
	}
	printf("Yes\n");
	for(int i=0;i<a*a;i++){
		if(i)printf(" ");
		printf("%d",ret[i]);
	}
	printf("\n");
}