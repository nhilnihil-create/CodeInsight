#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],b[N],cnt;
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]&1)cnt++;
    }
    if(cnt>2){puts("Impossible");return 0;}
    int flag=0;
    for(int i=1;i<=n;i++){
        if(a[i]&1){
            if(flag)swap(a[i],a[n]);
            else swap(a[i],a[1]),flag=1;
        }
    }
    for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
    if(n==1){
    	if(a[1]==1){
    		printf("%d\n%d\n",1,1);
    		return 0;
    	}
    	printf("%d\n",2);
    	printf("%d %d\n",a[1]-1,1);
    	return 0;
    }
    b[1]=a[1]+1;
    for(int i=2;i<=n;i++)b[i]=a[i];
    b[n]--;
    if(b[n])printf("%d\n",n);
    else printf("%d\n",n-1);
	if(!b[n])n--;
    for(int i=1;i<=n;i++)printf("%d%c",b[i]," \n"[i==n]);
    return 0;
}