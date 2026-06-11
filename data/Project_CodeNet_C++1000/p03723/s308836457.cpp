#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
  cin>>a>>b>>c;
  if(a== b && b == c && a % 2 != 1 ) 
    cout<<"-1";
  else{
    int count=0;
    while(a % 2 ==0 && b % 2 ==0 && c % 2 ==0){
   int d=b/2+c/2,e=c/2+a/2,f=a/2+b/2;
 	a=d;
  	b=e;
  	c=f;
  
  count++;
 	 }
cout<<count;
	}
}