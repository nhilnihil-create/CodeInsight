#include<stdio.h>
#include<string.h>
#include<algorithm>
#define LL long long 
using namespace std;
const int inf=1<<30;
const int maxn=1e5+5;
int A[maxn];

bool solve(int n)
{
int max_=-inf,min_=inf;		
for(int i=1;i<=n;i++)
{
  scanf("%d",&A[i]);	
  max_=max(max_,A[i]);
  min_=min(min_,A[i]);	
}	
	
	
if(max_-min_>1) return 0;
if(max_==min_)
{
if(max_==n-1||max_<=n/2 ) return 1;
else return 0;
}



if(max_>n-1) return 0;

int unique=0;

for(int i=1;i<=n;i++)
if(A[i]==min_) unique++;

max_-=unique;
n-=unique;

//printf("max=%d n=%d\n",max_,n);

if(max_>0&&max_<=n/2) return 1;
else 				  return 0;

}








int main(){
//freopen("C:\\Users\\deii\\Desktop\\test.txt","r",stdin);		

int n;
while(scanf("%d",&n)==1){

if(solve(n)) printf("Yes\n");
else printf("No\n");
}

}