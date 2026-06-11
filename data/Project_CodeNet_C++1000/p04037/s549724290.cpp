#include<cstdio>
#include<cstring>
#include<algorithm>
int n,ans,a[100100];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    std::sort(a+1,a+n+1);
    std::reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)	if(i+1>a[i+1]){
           					 	for(int j=i+1;a[j]==i;j++) ans^=1;
           					 	ans|=(a[i]-i)&1;
           					 	puts(ans? "First":"Second");
           					 	return 0;
        					}
} 