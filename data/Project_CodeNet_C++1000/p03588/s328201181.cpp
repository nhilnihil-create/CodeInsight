#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void){
int n;
int max=0;
int maxb;
int a[100005],b[100005];
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d %d",&a[i],&b[i]);
    if(a[i]>max){max=a[i];maxb=b[i];}
}

printf("%d\n",max+maxb);


}
