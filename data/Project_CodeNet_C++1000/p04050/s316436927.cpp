#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,m;
int a[100001];
int res[100001];

int main(void){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		printf("%d\n",a[0]);
		if(a[0]==1){
			printf("%d\n",1);
			printf("%d\n",1);
			return 0;
		}
		printf("%d\n",2);
		printf("%d %d\n",a[0]-1,1);
	}
	if(m==2){
		printf("%d %d\n",a[0],a[1]);
		if(a[0]==1){
			printf("%d\n",1);
			printf("%d\n",a[0]+a[1]);
			return 0;
		}
		printf("%d\n",2);
		printf("%d %d\n",a[0]-1,a[1]+1);
	}
	if(m>=3){
		int cnt=0;
		for(int i=0;i<m;i++){
			if(a[i]%2==1)cnt++;
		}
		if(cnt>2){
			printf("Impossible\n");
			return 0;
		}
		int p=min(cnt,1);
		cnt=0;
		for(int i=0;i<m;i++){
			if(a[i]%2==1){
				if(cnt==0)res[0]=a[i];
				else res[m-1]=a[i];
				cnt++;
			}else{
				res[i+p-cnt]=a[i];
			}
		}
		if(res[0]==1){
			for(int i=0;i<m;i++){
				printf("%d%c",res[i],i+1==m?'\n':' ');
			}
			printf("%d\n",m-1);
			res[m-1]++;
			for(int i=1;i<m;i++){
				printf("%d%c",res[i],i+1==m?'\n':' ');
			}
			return 0;
		}
		for(int i=0;i<m;i++){
			printf("%d%c",res[i],i+1==m?'\n':' ');
		}
		printf("%d\n",m);
		res[0]--;
		res[m-1]++;
		for(int i=0;i<m;i++){
			printf("%d%c",res[i],i+1==m?'\n':' ');
		}
	}
	return 0;
}
