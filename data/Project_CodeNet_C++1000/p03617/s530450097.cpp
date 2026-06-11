#include <iostream>
using namespace std;
int main(){
 	long long a,b,c,d,cnt=0;
  	cin>>a>>b>>c>>d;
  	long long n;
  	cin>>n;
  	n=n*4;
  	if(a*2<b)b=2*a;
  	if(a*4<c)c=4*a;
  	if(a*8<d)d=8*a;
  	if(b*2<c)c=2*b;
  	if(b*4<d)d=4*b;
  	if(c*2<d)d=2*c;
  	if(n>=8){
     	cnt+=n/8*d;
      	n=n%8;
    }
  	if(n>=4){
     	cnt+=n/4*c;
      	n=n%4;
    }
  	if(n>=2){
      	cnt+=n/2*b;
      	n=n%2;
    }
  	if(n>=1){
      	cnt+=n/1*a;     
    }
  	cout<<cnt;
}