#include <bits/stdc++.h>

const int N = 200001;
using namespace std; 

int n,a[N]; 
bool b[N]; 

bool check(int x){ 
	for(int i=1;i<=(n<<1)-1;++i)
		b[i]=(a[i]<=x); 
	for(int i=0;i<n;++i){
		if(b[n-i]==b[n-i-1])
			return b[n-i];
		if(b[n+i]==b[n+i+1])
			return b[n+i];} 
	return b[1]; 
} 

int main(){ 
	scanf("%d",&n);
	for(int i=1;i<=(n<<1)-1;++i)
		scanf("%d",a+i); 
	int l=1,r=(n<<1)-1,m; 
	while(l<r)
		if(check(m=l+r>>1))
			r=m;
		else l=m+1; 
	printf("%d",l); 
}
