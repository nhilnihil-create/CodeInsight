#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100010],cnt[2];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
bool check(){
	cnt[0]=cnt[1]=0;
	for(int i=1;i<=n;i++)
		cnt[a[i]&1]++;
	if(cnt[0]&1)
		return 1;
	if(cnt[1]>1)
		return 0;
	if(a[1]==1)
		return 0;
	int d=(a[1]-=(a[1]&1));
	for(int i=2;i<=n;i++){
		if(a[i]==1)
			return 0;
		d=gcd(d,a[i]-=(a[i]&1));
	}
	for(int i=1;i<=n;i++)
		a[i]/=d;
	return !check();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	puts(check()?"First":"Second");
	return 0;
}