#include <bits/stdc++.h>
int a[200001];
int main(){
int i,j,n;
long long h=0,b=0,w,k=-1;
scanf("%d",&n);
for(i=1;i<=n;i++){scanf("%d",&a[i]);h+=a[i];}
for(i=1;i<n;i++){
	b+=a[i];
	w=b-(h-b);
	if(w<0)w=-w;
	if((w<k)||(k==-1))k=w; 
}
printf("%lld",k);
return 0;
}

