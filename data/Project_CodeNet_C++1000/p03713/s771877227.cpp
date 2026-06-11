#include <bits/stdc++.h>
using namespace std;


  
int main(){

  int64_t h,w;
  cin>>h>>w;
  
  int64_t difference1,difference2,difference3,difference4;
  

  int64_t k=h/3;
  int64_t a,b,c;
  a=k*w;
  b=min(((w+1)/2)*(h-k),((h-k+1)/2)*w);
  c=h*w-a-b;
  difference1=max(a,max(b,c))-min(a,min(b,c));
  
  a=(k+1)*w;
  b=min(((w+1)/2)*(h-k-1),((h-k)/2)*w);
  c=h*w-a-b;
  difference2=max(a,max(b,c))-min(a,min(b,c));
  
  
  k=w/3;
  
  a=(k+1)*h;
  b=min(((h+1)/2)*(w-k-1),((w-k)/2)*h);
  c=h*w-a-b;
  difference3=max(a,max(b,c))-min(a,min(b,c));

  
  a=k*h;
  b=min(((h+1)/2)*(w-k),((w-k+1)/2)*h);
  c=h*w-a-b;
  difference4=max(a,max(b,c))-min(a,min(b,c));
  
  int64_t answer;
  
  answer=min(min(difference1,difference2),min(difference3,difference4));
  
  cout<<answer<<endl;
  

  

}
  













