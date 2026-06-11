#include<stdio.h>
int main(){
int n,i,j,k,l;
int count=0,even=0,odd=0;
int arr[100000];
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
if(arr[i]%2==0){
even++;
}
else if(arr[i]%2!=0){
odd++;
}
}
if(odd%2!=0 && n==3){
printf("YES");
}
else if(odd%2!=0 && n!=3){
printf("NO");
}
else if(odd%2==0){
printf("YES");
}

}
