#include<bits/stdc++.h>
using namespace std; 
int n,c,x[100105],m,d[100105],ans[100105],tmp[100105];
long long k;
double a[100105];
int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
    	scanf("%d",&x[i]);
	}
    scanf("%d%lld",&m,&k);
    for(int i = 1;i <= n;i++){
    	d[i] = i;
		ans[i] = i;
	}
    for(int i = 1;i <= m;i++){
        scanf("%d",&c);
        swap(d[c],d[c+1]);
    }
    while(k){
        if(k&1){
            for(int i = 1;i <= n;i++) tmp[i] = ans[d[i]];
            for(int i = 1;i <= n;i++) ans[i] = tmp[i];
        }
        for(int i = 1;i <= n;i++) tmp[i] = d[d[i]];
        for(int i = 1;i <= n;i++) d[i] = tmp[i];
        k >>= 1;
    }
    for(int i = 1;i <= n;i++) a[i] = x[ans[i]]-x[ans[i]-1];
    for(int i = 1;i <= n;i++){
    	printf("%0.1lf\n",a[i] += a[i-1]);
	}
    return 0;
}