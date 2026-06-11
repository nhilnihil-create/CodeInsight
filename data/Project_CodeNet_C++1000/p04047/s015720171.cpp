#include<bits/stdc++.h>
using namespace std;
int main(){
int i,j,n,l;

cin>>n;
int arr[202];
for(i=1;i<=(2*n);i++){

    cin>>arr[i];
}
sort(arr+1,arr+(2*n+1));

int sum=0;
for(i=1;i<=(2*n);i=i+2){
sum=sum+arr[i];

}
 printf("%d\n",sum);

return 0;
}
