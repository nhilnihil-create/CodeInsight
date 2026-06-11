#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,x;
  cin>>a>>b>>x;

  long long start = a;
  if(a%x!=0)start+=(x-a%x);
  
  long long end = b;
  if(b%x!=0)end-=b%x;
  
  if(end<start)cout<<0;
  else{
  	//end = start+(n-1)*x
    //(end-start)/x+1=n
    cout<<(end-start)/x+1;
  }
}