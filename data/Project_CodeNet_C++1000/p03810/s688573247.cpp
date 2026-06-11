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
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000


long long gcd(long long x,long long y){
if(x>y)swap(x,y);
if(x<=0)return y;
else if(y%x==0)return x;
else return gcd(y%x,x);
}



int main(){
	vector<long long>a;
	long long n, g,s;
	long long x, y, z;
	scanf("%lld", &n);
	f(i,n){
		scanf("%lld", &x);
		a.push_back(x);
	}
if(n==1){
printf("Second\n");
return 0;
}
x=0;
while(true){
y=0;
z=0;
s=0;
f(i,n){
if(a[i]%2==1){
y++;
z=i;
}
s+=a[i];
s=s%2;
}

if(y>1||a[z]==1||(s+n)%2==1){
if((s+n+x)%2==0){
printf("Second\n");
return 0;
}
else{
printf("First\n");
return 0;
}
}


a[z]--;
g=0;
f(i,n)g=gcd(g,a[i]);
f(i,n)a[i]=a[i]/g;

x=(x+1)%2;
}


	return 0;
}
