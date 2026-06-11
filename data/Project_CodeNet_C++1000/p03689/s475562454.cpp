#include<iostream>
using namespace std;
#define df 0
typedef long int li;

int main(){
  if(df) printf("*debug mode*\n");
  int H,W,h,w; cin >>H >>W >>h >>w;
  if(H%h==0 && W%w==0){
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  int a,b,q,r,p,m,d;
  if(W%w){b=W,a=w;} else{b=H,a=h;}
  q=b/a,r=b%a; // 1<=r<a
  d=a-r;
  m=r*(2*q+1),p=2*d*q;
  if(df)printf("a%d b%d q%d r%d p%d m%d d%d\n",a,b,q,r,p,m,d);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(W%w){
	printf("%d",j%a<r?p:-m);
      }else{
	printf("%d",i%a<r?p:-m);
      }
      printf("%c",j==W-1?'\n':' ');
    }
  }
}

/// confirm df==0 ///
