#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int SIZEN = 3 * 100010;
const int SIZEM = 100010;
int l[SIZEN] = {0},r[SIZEN] = {0};
int ans[SIZEM] = {0};
int N,M;


void Input(){
	scanf("%d%d",&N,&M);
	for(int i = 1;i <= N;i++)scanf("%d%d",&l[i],&r[i]);
}


void Judge(int x){
//	printf("x = %d\n",x);
	int ll,rr;
	int n = sqrt(l[x]);
	int last = M+1;
	for(int i = 1;i <= n;i++){
		if(l[x]%i == 0) ll = l[x]/i;
		else ll = l[x]/i+1;
		rr = r[x]/i;
		rr = min(last-1,rr);
		last = min(ll,last);
		if(ll > rr)continue;
		ans[ll]++;ans[rr+1]--;
	}
	for(int i = 1;i < last;i++){
		if(l[x]%i == 0) ll = l[x]/i;
		else ll = l[x]/i+1;
		rr = r[x]/i;
		if(ll > rr)continue;
		
		ans[i]++;ans[i+1]--;
	} 
} 
void Work(){
	for(int i = 1;i <= N;i++)Judge(i);
	for(int i = 1;i <= M;i++)ans[i] += ans[i-1];
	for(int i = 1;i <= M;i++)printf("%d\n",ans[i]);
}
int main(){
	Input();
	Work();
	return 0;
}