#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,j,c=0,n;
  cin>>n;
  n = n*2;
  int a[n];
  for(i=0;i<n;i++){
  cin>>a[i];
  }
  sort(a,a+n);
  for(i=0;i<n;i+=2){
  	c += a[i];
  }
  cout<<c;
}