#include<bits/stdc++.h>
using namespace std;
long long x[55];
bool cmp(long long p,long long q){
	return p>q;
}
double f(long long p,long long q){
	double s1=1;
	for(long long i=1;i<=q;i++){
		s1*=(p-i+1);
	}
	for(long long i=1;i<=q;i++){
		s1/=(i);
	}
	return s1;
}
int main(){
	long long n,a,b,g,h,s;
	double ss;
	scanf("%lld%lld%lld",&n,&a,&b);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	sort(x+1,x+n+1,cmp);
	g=x[1];
	h=x[a];
	s=0;
	for(long long i=1;i<=a;i++){
		s+=x[i];
	}
	if(g==h){
		printf("%.6f\n",1.000000*s/a);
		s=0;
		for(long long i=1;i<=n;i++){
			if(x[i]==g)s++;
		}
		ss=0;
		if(s>=b){
			for(long long i=a;i<=b;i++){
				ss+=f(s,i);
			}
		}
		else{
			for(long long i=a;i<=s;i++){
				ss+=f(s,i);
			}
		}
		printf("%.0f\n",ss);
	}
	else{
		printf("%.6f\n",1.000000*s/a);
		s=0;g=0;
		for(long long i=1;i<=a;i++){
			if(x[i]==h)g++;
		}
		for(long long i=1;i<=n;i++){
			if(x[i]==h)s++;
		}
		ss=f(s,g);
		printf("%.0f\n",ss);
	}
	return 0;
}