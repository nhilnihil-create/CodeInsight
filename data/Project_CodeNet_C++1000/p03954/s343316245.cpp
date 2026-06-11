#include<bits/stdc++.h>

using namespace std;

#define gc c=getchar()
#define r(x) read(x)

template<typename T>
inline void read(T&x){
    x=0;T k=1;char gc;
    while(!isdigit(c)){if(c=='-')k=-1;gc;}
    while(isdigit(c)){x=x*10+c-'0';gc;}x*=k;
}

const int N=2e5+7;

int n;

int a[N];

inline bool Greater(int i,int j,int x){
	return a[i]>x&&a[j]>x;
}

inline bool Smaller(int i,int j,int x){
	return a[i]<=x&&a[j]<=x;
}

inline bool check(int x){
	for(int i=0;i<n-1;++i){
		if(Greater(n-i-1,n-i,x)||Greater(n+i,n+i+1,x))return 0;
		if(Smaller(n-i-1,n-i,x)||Smaller(n+i,n+i+1,x))return 1;
	}
	return Smaller(1,1,x);
}
		

int main(){
	r(n);
	for(int i=1;i<2*n;++i)r(a[i]);
	int l=1,r=2*n-1,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
}
