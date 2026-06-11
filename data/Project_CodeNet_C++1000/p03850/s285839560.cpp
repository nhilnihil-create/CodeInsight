#include<bits/stdc++.h>
#define time Time
#define pii pair<int,int>    
#define x first    
#define y second 
#define N 10000005   
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))    
#define sqr(x) ((x)*(x))
typedef long long LL;  
using namespace std;
const int mod=1e9+7;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		long long 	int a[100005];
		int op[100005];
		op[0]=1;
		scanf("%lld",&a[0]);
		for(int i=1;i<n;i++){
			char c;
			while(scanf("%c",&c)&&c!='+'&&c!='-');
			if(c=='+')
			op[i]=1;
			else
			op[i]=0;
			scanf("%lld",&a[i]);
		} 
		long long int sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i];
		}
		long long int ans=1e18;
		int i;
		int last;
		for(i=0;op[i]==1;i++);
		long long int ssum=0,sssum=0;
		for(;i<n;i++)
		{
			ssum+=a[i];
			if(op[i]==0)
			sssum+=a[i],last=i;
			if(op[i+1]==0||i+1==n)
			ans=min(ssum+sssum-a[last],ans),ssum=0;
			//printf("%lld\n",sssum);
		}
		ans=min(sssum,ans);
		printf("%lld\n",sum-2*ans);
	}
}
/*

 1 - 1 + 2 + 10 - 2 + 3  + 5
 1  - 2  - 3  
*/
