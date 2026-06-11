#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  long long n;
  cin>>n;
  
  int minimum=100;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0){
      long long a=i;
      long long b=n/a;
      int cnt1=0;
      int cnt2=0;
      while(a>0){
	cnt1++;
	a/=10;
      }
      while(b>0){
	cnt2++;
	b/=10;
      }
      minimum=min(minimum,max(cnt1,cnt2));
    }
  }
  cout<<minimum<<endl;
  return(0);
}