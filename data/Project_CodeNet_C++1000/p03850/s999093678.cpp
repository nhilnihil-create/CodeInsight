#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
vector<long long>a;
vector<long long>b;
char c[10];
	int n;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
		scanf("%lld", &x);
s=x;
ans=x;
y=0;
	f(i, n-1){
scanf("%s",c);
scanf("%lld", &x);
ans+=x;
if(c[0]=='+'){
s+=x;
}
else{
y+=x;
a.push_back(s);
b.push_back(x);
s=0;
}
	}
a.push_back(s);
if(b.size()==0){
printf("%lld\n",ans);
return 0;
}
s=b[0]+a[1];
z=s;
	f(i, b.size()-1){
s+=(a[i+2]-a[i+1]+b[i+1]);
z=min(z,s);
	}
z=min(z,y);
ans-=(z*2);

	printf("%lld\n", ans);


	return 0;
}