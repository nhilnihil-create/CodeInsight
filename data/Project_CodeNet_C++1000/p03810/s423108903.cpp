#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100010;
int a[maxn],n;
int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}
bool pd(){
	 ll sum=0;
	 int ex=0,tot=0;
	 for(int i=1;i<=n;++i){
			 sum+=a[i]-1;
			 if(a[i]&1)tot++;
			 if(a[i]==1)ex=1;
	 }
	 if(ex)return sum%2;
	 if((n-tot)%2)return 1;
	 if(tot==1){
				int g=0;
				for(int i=1;i<=n;++i)if(a[i]&1)a[i]--;
				for(int i=1;i<=n;++i)g=gcd(g,a[i]);
				for(int i=1;i<=n;++i)a[i]/=g;
				return pd()^1;
	 }
	 return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
	}
	if (pd()) printf("First");
 	else printf("Second");
 	//system("pause");
	return 0;
}