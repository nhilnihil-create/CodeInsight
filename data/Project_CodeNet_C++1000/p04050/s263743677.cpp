#include <bits/stdc++.h>

using namespace std; 

int n,m,a[105],b[105]; 

int main(){
	int odd,p1,p2,ma,mb; 
	cin>>n>>m; 
	for(int i=1; i<=m; ++i) cin>>a[i]; 
	odd=p1=p2=0; 
	for(int i=1; i<=m; ++i)
		if(a[i]&1){
			++odd;
			if(!p1) p1=i; 
			else if(!p2) p2=i; 
		}
 	if(odd>2) {
		puts("Impossible"); 
		return 0;
	}
	ma=mb=m; 
	if(ma>1){
		if(p1&&p2&&a[p1]<a[p2]) swap(a[p1],a[p2]); 
		if(p1) swap(a[1],a[p1]); 
		if(p2) swap(a[ma],a[p2]); 
		for(int i=2; i<ma; ++i) b[i]=a[i]; 
		b[1]=a[1]+1; 
		b[mb]=a[ma]-1; 
		if(!b[mb]) --mb; 	
	}
	if(ma==1){
		mb=2;
		b[1]=1; 
		b[2]=n-1;
		if(!b[mb]) --mb; 
	}
	for(int i=1; i<=ma; ++i) { cout<<a[i]; putchar(i==ma?'\n':' '); }	 
	cout<<mb<<endl; 
	for(int i=1; i<=mb; ++i) { cout<<b[i]; putchar(i==mb?'\n':' '); }  
	return 0; 
} 