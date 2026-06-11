#include<bits/stdc++.h>
using namespace std;
int main(){
long long n,m,i,k,p,r;
cin>>n>>m;long long a[m];
for(i=0;i<m;i++){
cin>>a[i];
}sort(a,a+m);
r=a[m-1];
p=2*(n-r);
k=n-p-1;
if(k<0)
cout<<0;
else
cout<<k;
return 0;
}